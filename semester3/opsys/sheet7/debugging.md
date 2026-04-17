# Exercise sheet 7


## Debugging using gdb

```C

GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
(gdb) break main.c:9
No symbol table is loaded.  Use the "file" command.
Make breakpoint pending on future shared library load? (y or [n]) n
(gdb) file main.c
"/mnt/c/Users/Nutzer/Documents/programming scripts/uni/semester3/opsys/sheet7/main.c": not in executable format: file format not recognized
(gdb) file out
Reading symbols from out...
(gdb) break out:9
No source file named out.
Make breakpoint pending on future shared library load? (y or [n]) n
(gdb) break main.c:9
Breakpoint 1 at 0x1163: file main.c, line 11.
(gdb) breakpoints
Undefined command: "breakpoints".  Try "help".
(gdb) break main.c:7
Breakpoint 2 at 0x1155: file main.c, line 7.
(gdb) help
List of classes of commands:

aliases -- User-defined aliases of other commands.
breakpoints -- Making program stop at certain points.
data -- Examining data.
files -- Specifying and examining files.
internals -- Maintenance commands.
obscure -- Obscure features.
running -- Running the program.
stack -- Examining the stack.
status -- Status inquiries.
support -- Support facilities.
text-user-interface -- TUI is the GDB text based interface.
tracepoints -- Tracing of program execution without stopping the program.
user-defined -- User-defined commands.

Type "help" followed by a class name for a list of commands in that class.
Type "help all" for the list of all commands.
Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
Type "apropos -v word" for full documentation of commands related to "word".
Command name abbreviations are allowed if unambiguous.
(gdb) running
Undefined command: "running".  Try "help".
(gdb) run out
Starting program: /mnt/c/Users/Nutzer/Documents/programming scripts/uni/semester3/opsys/sheet7/out out
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 2, main () at main.c:7
warning: Source file is more recent than executable.
7               int a = 3;
(gdb)
(gdb) stack
Undefined command: "stack".  Try "help".
(gdb) help stack
Examining the stack.
The stack is made up of stack frames.  Gdb assigns numbers to stack frames
counting from zero for the innermost (currently executing) frame.

At any time gdb identifies one frame as the "selected" frame.
Variable lookups are done with respect to the selected frame.
When the program being debugged stops, gdb selects the innermost frame.
The commands below can be used to select other frames by number or address.

List of commands:

backtrace, where, bt -- Print backtrace of all stack frames, or innermost COUNT frames.
down, dow, do -- Select and print stack frame called by this one.
faas -- Apply a command to all frames (ignoring errors and empty output).
frame, f -- Select and print a stack frame.
frame address -- Select and print a stack frame by stack address.
frame apply -- Apply a command to a number of frames.
frame apply all -- Apply a command to all frames.
frame apply level -- Apply a command to a list of frames.
frame function -- Select and print a stack frame by function name.
frame level -- Select and print a stack frame by level.
frame view -- View a stack frame that might be outside the current backtrace.
return -- Make selected stack frame return to its caller.
select-frame -- Select a stack frame without printing anything.
select-frame address -- Select a stack frame by stack address.
select-frame function -- Select a stack frame by function name.
select-frame level -- Select a stack frame by level.
select-frame view -- Select a stack frame that might be outside the current backtrace.
up -- Select and print stack frame that called this one.

Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
Type "apropos -v word" for full documentation of commands related to "word".
Command name abbreviations are allowed if unambiguous.
(gdb) frame view
quit
Missing address argument to view a frame
(gdb) frame view 0x1155

#0  0x0000000000000000 in ?? ()
(gdb) frame view 0x1156

#0  0x0000000000000000 in ?? ()
(gdb) frame view 0x1157

#0  0x0000000000000000 in ?? ()
(gdb) frame view 0x1158

#0  0x0000000000000000 in ?? ()
(gdb) frame view 9

#0  0x0000000000000000 in ?? ()
(gdb) frame function add

No frame for function "add".
(gdb) frame function main

#0  main () at main.c:7
7               int a = 3;
(gdb) run

The program being debugged has been started already.
Start it from the beginning? (y or n) n

Program not restarted.
(gdb) continue

Continuing.

Breakpoint 1, main () at main.c:11
11      }

(gdb) continue

Continuing.
3 + 2 = 5
[Inferior 1 (process 1462) exited normally]

(gdb) q

```

