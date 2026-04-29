# Uni Repo

This repository contains personal university material, notes, and projects.

All content is provided as-is. I make no guarantees regarding correctness, completeness, or accuracy.


## Noteable content

### semester2/ra_tawdross/mars.bat

A batch file used to executed .asm (mips) directly from the console without opening mars. Usage: 

	mars program.asm

### semester2/cpp_unthan/make.bat & semester2/cpp_unthan/tools/make.py 

A self written __Makefile interpreter__ for windows, which can directly be used inside the C++ directory.

Usage (while inside ```semester2/cpp_unthan/```):

	make <defined makefile instruction>

It's important to note that this interpreter only supports makefile semantic that has been used inside the lecture, e.g. Instructions and Variables.

#### Example Code:

Inside the Makefile:
```Makefile
flag := -std=c++11

ex1: uebung1.cpp
	g++ $(flag) uebung1.cpp -o uebung1.exe
	uebung1.exe
```
Inside the Terminal:
```batch
make ex1
```
Requires python 3.12.5+

If the execution of make.bat fails, ensure that the correct python version is called with the command "python". Sometimes newer versions take other names like "py" when "python" is already occupied.

You can check this with

	python -V