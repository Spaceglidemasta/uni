.data
    input: .asciiz "Geben Sie einene String an: "
    input2: .asciiz "Geben Sie einen Char an: "
    output1: .asciiz "Der char kommt "
    output2: .asciiz "-mal im String vor."

    buffer: .space 32


.text

    li $v0, 4
    la $a0, input
    syscall

    li $v0, 8
    la $a0, buffer
    li $a1, 32
    syscall
    move $t0, $a0

    li $v0, 4
    la $a0, input2
    syscall

    li $v0, 12
    syscall

    move $a0, $t0
    move $a1, $v0
    jal count

    move $t0, $v0

    li $v0, 4
    la $a0, output1
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 4
    la $a0, output2
    syscall


    li $v0, 10
    syscall

    count:

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
