# MIPS Assembler-Code zur Umwandlung einer Ganzzahl (0-3999) in eine römische Zahl
# C++ Referenzfunktion siehe unten

# ------------------------------------------------------------
# C++:
# vector<int> base = {1, 4, 5, ..., 1000};
# vector<string> sym = {"I", "IV", "V", ..., "M"};
# string res = "";
# while (x > 0) {
#     int div = x / base[i];
#     while (div--) res += sym[i];
#     x = x % base[i];
#     i--;
# }
# ------------------------------------------------------------

.data
    info: .asciiz "Geben Sie eine positive ganze Zahl von 0 bis 3999 an: "
    cancel_info: .asciiz "Diese Zahl liegt nicht zwischen 0 und 3999!\n"

    eins: .asciiz "I"
    vier: .asciiz "IV"
    funf: .asciiz "V"
    neun: .asciiz "IX"
    zehn: .asciiz "X"
    vierzig: .asciiz "XL"
    funfzig: .asciiz "L"
    neunzig: .asciiz "XC"
    hundert: .asciiz "C"
    vierhunder: .asciiz "CD"
    funfhundert: .asciiz "D"
    neunhundert: .asciiz "CM"
    tausend: .asciiz "M"

    base_values: .word 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
    sym_array:   .word eins, vier, funf, neun, zehn, vierzig, funfzig, neunzig, hundert, vierhunder, funfhundert, neunhundert, tausend

.text

    
    li $v0, 4
    la $a0, info
    syscall

    li $v0, 5
    syscall
    move $t0, $v0      # $t0 = x

    #if (x < 0 || x > 3999) { cout << cancel_info; return; }
    li $t1, 3999
    blt $t1, $t0, cancel
    blt $t0, $zero, cancel

    li $t3, 12          # int i = base.size() - 1 (12 Elemente)

convert_loop:
    #while (x > 0 && i >= 0)
    blt $t0, 1, end_convert
    blt $t3, 0, end_convert

    la $t4, base_values
    la $t5, sym_array

    sll $t6, $t3, 2   # Offset = i * 4
    add $t7, $t4, $t6
    lw $t8, 0($t7)      # base[i]

    
    div $t0, $t8        #div = x / base[i]
    mflo $t9            # div
    mfhi $t0            # x = x % base[i]

    beq $t9, $zero, next_i    # if (div == 0): next_i

print_loop:
    beq $t9, $zero, next_i

    #cout << sym[i];
    add $t7, $t5, $t6
    lw $a0, 0($t7)
    li $v0, 4
    syscall

    addi $t9, $t9, -1
    j print_loop

next_i:
    addi $t3, $t3, -1    # i--
    j convert_loop

end_convert:
    li $v0, 10
    syscall

cancel:
    li $v0, 4
    la $a0, cancel_info
    syscall
    li $v0, 10
    syscall
