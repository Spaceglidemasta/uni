.data
    info: .asciiz "Geben Sie n an: "
    end_info: .asciiz "Ergebnis: "

.text

    la $a0, info
    li $v0, 4
    syscall
    li $v0, 5
    syscall 

    move $a0, $v0
    jal fakt

    move $t0, $v0

    la $a0, end_info
    li $v0, 4
    syscall
    move $a0, $t0
    li $v0, 1
    syscall


    li $v0, 10
    syscall


    fakt:
    addi $sp, $sp, 8
    sw $a0, 0($sp)
    sw $ra, 4($sp)

    li $v0, 1
    blt $a0, $v0, end_fakt
    
    addi $a0, $a0, -1

    jal fakt

    lw $a0, 0($sp)

    mul $v0, $v0, $a0



    end_fakt: 
    lw $ra 4($sp)
    addi $sp, $sp -8
    jr $ra
        


        