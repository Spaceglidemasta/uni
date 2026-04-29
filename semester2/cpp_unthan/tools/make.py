#!/usr/bin/env python
from enum import Enum
import os
import subprocess as sp
import sys


def end_program():
    print("Makefile terminated.")
    exit()

def print_SyntaxError(line:str, column:int, msg:str) -> None:
    """
    Prints the SE together with the position of the SE.

    
    Example

    ::
    
        Symbol definitions cannot contain whitespaces:
        weird variable := value
             ^

    line
        The line as str where the error took place. Automatically removes trailing newlines

    column
        The column where the error took place

    msg 
        The message to be shown before the error

    
    """
    
    print(msg)

    print(line.removesuffix("\n"))

    print(f"{" " * (column - 1)}^")



class TokType(Enum):
    NAME = 1
    FILE_NAME = 2
    COMMAND_SEP = 3
    COMMAND_LINE = 4
    VAR_SEP = 6
    VAR_VALUE = 7
    INVALID = 100

class ScanMode(Enum):
    BASE = 1
    COMMAND_DEF = 2
    VAR_DEF = 3
    COMMAND_LINE = 5
    BASE_DEF = 6
    INVALID = 100

class LineType(Enum):
    VAR = 1
    COMMAND = 2
    COMMAND_LINE = 3
    EMPTY = 4
    INVALID = 100


class Token:

    def __init__(self, type: TokType, value: str) -> None:
        self.type = type
        self.value = value

    def __str__(self) -> str:
        return f"Token {self.type.name}: {self.value}"
        
    
class Line:

    def __init__(self, type:LineType, tokens:list[Token]) -> None:
        self.type = type
        self.tokens = tokens

    def __str__(self) -> str:
        return f"{self.type.name}=\"{"".join([tok.value for tok in self.tokens])}\""
    
    
class Instruction:
    """
    Represents one Instruction to be invoked upon the console

    Attributes
    ----------
    name : str
        a formatted string to print out what the animal says
    file : str
        the name of the animal
    commands : list[str]
        the sound that the animal makes
    
    """


    def __init__(self, header:Line, commands: list[Line]) -> None:

        if header.type != LineType.COMMAND:
            raise RuntimeError("Command header of wrong type. This is an internal error.")
        
        self.name:str = header.tokens[0].value
        self.file:str = header.tokens[-1].value #more secure then [2], altough in praxis, this should not make a difference

        #the tokens array of a COMMAND_LINE is trivial, as it only has one entry
        self.commands:list[str] = [cmd.tokens[0].value for cmd in commands]

    def __str__(self) -> str:
        
        s:str = ""
        s += f"{self.name}: {self.file}\n"

        #rare instance where .join would make this more complicated        
        for cmd in self.commands:
            s += f"\t{cmd}\n"

        return s
    
    def execute(self):
        
        for cmd in self.commands:
            sp.run(cmd, shell = True)


def lines_to_instructions(lines:list[Line]) -> list[Instruction]:
    
    current_header:Line | None = None
    current_command_lines:list[Line] = []
    instructions:list[Instruction] = []

    for line in lines:

        #print(str(line.type.name) + str([tok.value for tok in line.tokens]))

        if line.type == LineType.COMMAND:

            if current_header != None:
                instructions.append(
                    Instruction(current_header, current_command_lines)
                )

            current_header = line
            current_command_lines = []

        elif line.type == LineType.COMMAND_LINE:
            current_command_lines.append(line)

        else: #ignore variables
            continue
    
    #flush the buffer one more time to include the last command too
    if current_header != None:
                instructions.append(
                    Instruction(current_header, current_command_lines)
                )
    

    return instructions



def tokenize(line:str) -> Line:

    tokens:list[Token] = []
    current:str = ""
    current_type:TokType = TokType.INVALID;
    mode:ScanMode = ScanMode.BASE
    inst_type:LineType = LineType.EMPTY

    ws_count:int = 0
    charcount:int = 0


    for char in list(line):

        charcount += 1

        current_type = TokType.INVALID

        match mode:

            case ScanMode.BASE:

                if char == ":":

                    ws_count = 0 #techically redundant, may be useful later

                    tokens.append(Token(TokType.NAME, current))

                    mode = ScanMode.BASE_DEF
                    
                    current = ":"

                    continue

                elif char == "\t" and current == "":
                    mode = ScanMode.COMMAND_LINE
                    inst_type = LineType.COMMAND_LINE

                    continue

                elif char == "\t" and current != "":
                    continue

                elif char == "\n" and current == "":
                    continue #this will lead to return of empty Instruction

                elif char == "\n" and current != "": #case where there is text in the middle of nowhere
                    #raise SyntaxError("Expected \":\" or \":=\", found newline")
                    print_SyntaxError(line, charcount, "Expected \":\" or \":=\", found newline")
                    end_program()
                    


                if char.isspace():
                    ws_count += 1
                    continue

                #aka when not whitespace after whitespace in NAME defintion
                #example:
                #var name := 3
                #   ^
                if ws_count != 0:

                    #TODO change this behavior to goofy var later, as this is an intented feature in unix makefile
                    if char == "=":
                        print_SyntaxError(line, charcount - 1, "Unsupported Syntax. Did you forget a \":\"?")

                    else :
                        print_SyntaxError(line, charcount - 1, "Whitespaces are not allowed in Symbol definitions:")
                    
                    end_program()

                #TokType will be NAME
                current += char
                
            case ScanMode.BASE_DEF:

                if char == "=":
                    mode = ScanMode.VAR_DEF
                    inst_type = LineType.VAR

                    tokens.append(Token(TokType.VAR_SEP, ":="))
                    #technically the string is reduntant, as there is only one variable seperator: ":=" 

                    current = ""
                    continue
                
                #the case where there is only ": "
                mode = ScanMode.COMMAND_DEF
                inst_type = LineType.COMMAND
                
                tokens.append(Token(TokType.COMMAND_SEP, ":")) #once again the string is technically useless

                current = char
                current_type = TokType.FILE_NAME

                continue
            
            case ScanMode.COMMAND_DEF:

                current_type = TokType.FILE_NAME
                    
                current += char


            case ScanMode.VAR_DEF:

                current_type = TokType.VAR_VALUE

                if char.isspace() and current == "":
                    continue            

                current += char
                
                

            case ScanMode.COMMAND_LINE:
           
                current_type = TokType.COMMAND_LINE
                
                current += char

    if current_type != TokType.INVALID:
        
        tokens.append(Token(current_type, current.removesuffix("\n")))

    return Line(inst_type, tokens)

def extract_vars(
        lines: list[Line]
    ) -> dict[str,str]:

    varmap: dict[str,str] = {}

    for line in lines:

        #!unsafe in theory, change later
        if line.type == LineType.VAR:
            
            varmap[line.tokens[0].value] = line.tokens[2].value
            
    return varmap


def evaluate_vars(
        lines: list[Line],
        bonus_defines: dict[str,str] | None = None 
        ) -> list[Line]:
    '''
    Evalutes the variables over the given lines.
    O(n³) in theory, O(n²) in practice
    
    :param lines: A given list of Lines objects
    :type lines: list[Line]
    :param bonus_defines: bonus variables which may be defined 
    :type bonus_defines: dict[str, str]
    :return: the modified lines list with all values inserted
    :rtype: bool
    '''

    # "bonus_defines = {}" as default arg is not working,
    # because in python, default args of type dict are static (???)
    if bonus_defines is None:
        bonus_defines = {}

    #bonus_defines overwrites existing variables in extract_vars(lines)
    varmap: dict[str, str] = extract_vars(lines) | bonus_defines

    retlines: list[Line] = []

    for line in lines:

        #only command_line's support variables
        if line.type != LineType.COMMAND_LINE:
            retlines.append(line)
            continue
        
        for key, val in varmap.items():

            for token in line.tokens:

                token.value = token.value.replace(f"$({key})", val)
        
        
        retlines.append(line)

    return retlines;


def read_file(filename: str) -> list[Line]:

    lines:list[Line] = []
    with open(filename) as f:

        for line in f:
            
            if(line == "\n"):
                continue

            lines.append(tokenize(line))

    return lines

def get_makefile() -> str | None:

    currentdir:list[str] = os.listdir()
    
    if "Makefile" in currentdir:
        return "Makefile"
    elif "makefile" in currentdir:
        return "makefile"
    else:
        print("Could not find Makefile. Acceptable names are: \n\"Makefile\" and \"makefile\"")
        return None


def get_targets() -> list[str]:

    return args if (args := sys.argv[1:]) else ["default"]



if __name__ == "__main__":

    makefilename = get_makefile()

    if not makefilename:
        exit()

    targets:list[str] = get_targets()


    lines = read_file(makefilename)
    evlines = evaluate_vars(lines)
    instructions = lines_to_instructions(evlines)


    not_found:list[str] = []
    for target in targets:

        for intstruct in instructions:
            
            if intstruct.name == target:
                #print(f"executing {target}...")
                #print(str(intstruct))
                intstruct.execute()
                break

        else:
            not_found.append(target)


    for target in not_found:    
        
        if target == "default":

            print("No default command / instruction was found.\nDeclare it via:\ndefault: file.name ...")
        
        else:
            print(f"No command / instruction with the name {target} was found.\nDeclare it via:\n{target}: file.name ...")

    
