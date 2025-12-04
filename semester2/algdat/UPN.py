#TRENNZEICHEN HIER EINSTELLEN:
SEPERATOR = " "

eingabe = input("Geben Sie ein arithmetischen Ausdruck in UPN an: ")
eingabe = eingabe.split(SEPERATOR)

arithmetics = ["+","-","*","/"]

def calculate(array: list):

    if len(array) == 1:
        return array[0]

    for letter in array:
        if letter in arithmetics:
            i = array.index(letter)
            print(array[:i - 2] + [str(eval(array[i - 2] + letter + array[i - 1]))] + array[i + 1:])
            #                alles vorher  +   ergebnis von a[i-2] und a[i-1] auf operator     + alles danach
            return calculate(array[:i - 2] + [str(eval(array[i - 2] + letter + array[i - 1]))] + array[i + 1:])
            


#Beispiel Eingabe: 2 3 * 4 5 + - 5 4 * /    => -0.15
#Bitte trennzeichen einstellen
print(calculate(eingabe))







