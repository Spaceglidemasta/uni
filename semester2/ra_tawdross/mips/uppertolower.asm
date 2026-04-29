.data 
    input: .asciiz "Geben Sie einen String an: "
    output: .asciiz "Output String: "
    buffer: .space 32


.text

    li $v0, 4
    la $a0, input
    syscall

    li $v0, 8
    la $a0, buffer
    li $a1, 32
    syscall

    jal upper

    li $v0, 4
    syscall


    li $v0, 10
    syscall

    upper:

        li $t1, 'A'
        li $t2, 'Z'

        move $s0, $a0

        loop:

            lb $t0, 0($a0)

            beq $t0, $zero, end_loop


            bgt $t0, $t2, skip
            blt $t0, $t1, skip

            addi $t0, $t0, 32
            sb $t0, 0($a0)

            skip:

            addi $a0, $a0, 1

            j loop

        end_loop:

            move $a0, $s0

            jr $ra
