.data

    input: .asciiz "Geben Sie eine ganze, positive Zahl ein: "
    output: .asciiz "Fakultät: "

.text

    li $v0, 4
    la $a0, input
    syscall

    li $v0, 5
    syscall

    move $a0, $v0
    
    jal fakt

    move $t0, $v0

    li $v0, 4
    la $a0, output
    syscall

    li $v0, 1
    move $a0, $t0
    syscall


    li $v0, 10
    syscall


    fakt:
        li $v0, 1

        addi $sp, $sp, -8
        sw $a0, 0($sp)
        sw $ra, 4($sp)

        
        beq $a0, $v0, end_fakt

        addi $a0, $a0, -1

        jal fakt

        lw $a0, 0($sp)

        mul $v0, $v0, $a0


        end_fakt:
        lw $ra, 4($sp)
        addi $sp, $sp, 8

        jr $ra
