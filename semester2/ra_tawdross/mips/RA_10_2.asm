.data

    p_in: .asciiz "Geben Sie p an: "
    q_in: .asciiz "Geben Sie q an: "

    solutions: .asciiz " Lösung(en):\n"

    sol_1: .asciiz "Lösung 1: "
    sol_2: .asciiz "Lösung 2: "

    const0: .double 0.0
    constm1: .double -1.0
    const2: .double 2.0
    const4: .double 4.0

    enter_out: .asciiz "\n"


.text

    #p: f12
    #q: f14
    #D: f16
    #x1: f8
    #x2: f10

    #p in
    li $v0, 4
    la $a0, p_in
    syscall

    li $v0, 7
    syscall
    mov.d $f12, $f0

    #p in
    li $v0, 4
    la $a0, q_in
    syscall

    li $v0, 7
    syscall
    mov.d $f14, $f0

    jal quadsolve
    move $t1, $v0

    li $v0, 1
    move $a0, $t1
    syscall

    li $v0, 4
    la $a0, solutions
    syscall

    li $t0, 1
    beq $t1, $zero, end_programm
    nop
    beq $t1, $t0, ein 
    #2 lösungen:
    li $v0, 4
    la $a0, sol_1
    syscall
    li $v0, 3
    mov.d $f12, $f0
    syscall
    li $v0, 4
    la $a0, enter_out
    syscall

    li $v0, 4
    la $a0, sol_2
    syscall
    li $v0, 3
    mov.d $f12, $f2
    syscall
    
    j end_programm


    ein:
    li $v0, 4
    la $a0, sol_1
    syscall
    li $v0, 3
    mov.d $f12, $f0
    syscall


    end_programm:
    li $v0, 10
    syscall

#unsigned int quadsolve(double p, double, q)
quadsolve:

    #D:
    ldc1 $f4, const4
    mul.d $f16, $f12, $f12
    div.d $f16, $f16, $f4
    sub.d $f16, $f16, $f14

    #D < 0
    ldc1 $f4, const0
    c.lt.d $f16, $f4
    bc1t kreelle
    nop
    #D == 0
    c.eq.d $f16, $f4
    bc1t ereelle
    nop
    #D > 0
    li $v0 2

    ldc1 $f4, const2
    div.d $f0, $f12, $f4
    ldc1 $f4, constm1
    mul.d $f0, $f0, $f4

    #split +-
    mov.d $f2, $f0

    sqrt.d $f16, $f16

    #x1
    sub.d $f0, $f0, $f16

    #x2
    add.d $f2, $f2, $f16
    
    j quadsolve_end

    kreelle:
    li $v0, 0

    j quadsolve_end

    ereelle:
    li $v0, 1

    ldc1 $f4, const2
    div.d $f0, $f12, $f4
    ldc1 $f4, constm1
    mul.d $f0, $f0, $f4

    j quadsolve_end

    quadsolve_end:
    jr $ra