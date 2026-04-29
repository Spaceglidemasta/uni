.data

    input: .asciiz "Geben Sie den String ein: "
    output: .asciiz "Ergebnis in uppercase: "

    buffer: .space 32

.text

    li $v0, 4
    la $a0, input
    syscall

    li $v0, 8
    la $a0, buffer
    li $a1, 32
    syscall
    
    jal toupper

    move $t0, $a0

    li $v0, 4
    la $a0, output
    syscall

    li $v0, 4
    move $a0, $t0
    syscall

    li $v0, 10
    syscall



    #toupper(*string)
    toupper:

        li $t2, 'a'
        li $t3, 'z'

        move $s0, $a0

        loop:

            lb $t1, 0($a0)

            beq $t1, $zero, end_loop
            blt $t1, $t2, skip
            bgt $t1, $t3, skip

            addi $t1, $t1, -32

            sb $t1, 0($a0)

            skip:

            addi $a0, $a0, 1

            j loop

        end_loop:

            move $a0, $s0

            jr $ra


            