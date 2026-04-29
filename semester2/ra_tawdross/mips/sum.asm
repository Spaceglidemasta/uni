.data
    input: .asciiz "Geben Sie eine ganze, positive, Zahl an: "
    output: .asciiz "Summe aller Zahlen bis zur Zahl: "

.text

    li $v0, 4
    la $a0, input
    syscall

    li $v0, 5
    syscall

    move $a0, $v0

    jal sum

    move $t0, $v0

    li $v0, 4
    la $a0, output
    syscall

    li $v0, 1
    move $a0, $t0
    syscall
    

    li $v0, 10
    syscall

    sum: 
        li $v0, 0

        addi $sp, $sp, -8
        sw $a0, 0($sp)
        sw $ra, 4($sp)

       
        bgt $v0, $a0, end_sum

        addi $a0, $a0, -1

        jal sum

        lw $a0, 0($sp)

        add $v0, $v0, $a0

    end_sum:
        lw $ra 4($sp)
        addi $sp, $sp, 8

        jr $ra

