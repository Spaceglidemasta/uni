.data 
    input: .asciiz "Geben Sie kek: "
    output: .asciiz "fibonatsch: "

.text
    
    li $v0, 4
    la $a0, input
    syscall

    li $v0, 5
    syscall

    move $a0, $v0

    jal fib

    move $t0, $v0

    li $v0, 4
    la $a0, output
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 10
    syscall

    fib:
    
        addi $sp, $sp, -12
        sw $a0, 0($sp)
        sw $ra, 4($sp)
        

        li $t0, 2
        blt $a0, $t0, endfib

        addi $a0, $a0, -1

        jal fib

        sw $a0, 8($sp)

        addi $sp, $sp, -12

        jal fib

        lw $t1, 8($sp)

        add $v0, $a0, $t1

		addi $sp, $sp, 12


    endfib:
    lw $ra, 4($sp)

    addi $sp, $sp, 12

    jr $ra

    



