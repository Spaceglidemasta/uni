.data
    str_info: .asciiz "\nGeben Sie den String an: "
    c_info: .asciiz "Geben Sie den char an: "
    end_info_1: .asciiz "Der String enthält den char "
    end_info_2: .asciiz " mal."
    question: .asciiz "\nProgramm neustarten? (0 für Ja) "

    buffer: .space 32


.text
    main_loop:

    li $v0, 4
    la $a0, str_info
    syscall
    la $a0, buffer
    li $a1, 32
    li $v0, 8
    syscall
    move $t0, $a0

    li $v0, 4
    la $a0, c_info
    syscall
    li $v0, 12
    syscall
    move $t1, $v0


    move $a0, $t0
    move $a1, $t1


    jal ncstr
    move $t0, $v0
    
    li $v0, 4
    la $a0, end_info_1
    syscall
    li $v0, 1
    move $a0, $t0
    syscall
    li $v0, 4
    la $a0, end_info_2
    syscall


    li $v0, 4
    la $a0, question
    syscall
    li $v0, 5
    syscall

    beq $v0, $zero, main_loop

    li $v0, 10
    syscall


    #int ncstr(char *str, char c)
    ncstr:
        li $v0, 0

        loop:
            lb $t0, 0($a0)

            beq $t0, $zero, end_loop

            bne $t0, $a1, isnt_equal
            addi $v0, $v0, 1

            isnt_equal:
            addi $a0, $a0, 1
            j loop

        end_loop:
            jr $ra




