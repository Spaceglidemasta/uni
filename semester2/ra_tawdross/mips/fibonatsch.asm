.data
    input:  .asciiz "Geben Sie ihren String an:  "
    inputchar: .asciiz "Geben Sie den char an: "
    output: .asciiz "Der char kommt "
    output2: .asciiz "-mal im String vor."

    buffer: .space 32

.text
    li $v0, 4
    la $a0, input
    syscall

    li $v0, 8
    la $a0, buffer
    la $a1, 32
    syscall

    move $t0, $a0

    li $v0, 4
    la $a0, inputchar
    syscall

    li $v0, 12
    syscall
    move $a1, $v0

    move $a0, $t0

    jal testchar

    move $t0, $v0

    li $v0, 4
    la $a0, output
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 4
    la $a0, output2
    syscall

    endprg:
    li $v0, 10
    syscall

    testchar:

    li $v0, 0

    loop:

        lb $t0, 0($a0)

        beq $t0, $zero, end_loop

        bne $t0, $a1, skip
        addi $v0, $v0, 1

        skip:

        addi $a0, $a0, 1
        
        j loop

    end_loop:

    jr $ra
    
