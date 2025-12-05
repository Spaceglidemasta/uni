
##### Aufteilung: 
- ~20%: Theorie
- ~40%: Logisim
- ~40%: MIPS 

# 1: Theorie
- Fragen zur Core Functionility von RISC & CISC, sowie vor- und nachteile.

- Eine frage zum unterschied von Barrelshift und Shiftregister

- Data- & Controlhazards in MIPS code erkennen

- Byte Size von C-Structs ausrechnen

- Memory addresses von der .data Sektion in MIPS ausrechnen (mit .align und .space)

- Wissen wie groß doubles, (short-) ints, floats, chars, bytes und words sind.

- Big & Small Endian

- Padding und alignment verstehen

-

# 2: Logisim

- 4 Bit ALU mit 4 operationen (2bit opcode) bauen [~10p, medium]

- Zustandsdiagram (Mealy oder Moore) nur mit D-FlipFlops und ROM darstellen; Zustandstabelle war auch anzugeben [~14p, medium -> geschenkt wenn man mit ROMs umgehen kann]

- Boolische funktionen mit 2 Konstanten (0 & 1) und Demultiplexern darstellen [6p, einfach]

- 4 Bit Subtraktion nur mit 1 Bit Additionsregistern und NOT darstellen (Kein ADD, XOR, usw.), mit carry out [14p, sehr schwer]

Es musste nirgendswo eine Subschaltung miteingebaut sein, sollte wohl aber eigentlich Klausurrelevant sein.

# 3: MIPS

- String & 2 Chars einlesen und dann per funktion (jal func) Ein String so modifizieren dass char 1 durch char 2 ausgetauscht wird. -> func(char* a0, char a1, char a2)
In der Hauptklausur kam String: klein zu großbuchstaben drann; String manipulation scheint beliebt zu sein. [__40p__, leicht - medium]
    + Man kann die ASCII tabelle in der Klausur mit "man ascii" in der Konsole aufrufen.