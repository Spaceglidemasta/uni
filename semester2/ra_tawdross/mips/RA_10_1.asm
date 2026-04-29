.data

    enter_out: .asciiz "\n"

    m_info: .asciiz "Geben Sie m an: "
    n_info: .asciiz "Geben Sie n an: "

    m_hex: .asciiz "(hex) m: "
    n_hex: .asciiz "(hex) n: "

    q_out: .asciiz "(dez) Quotient: "
    r_out: .asciiz "(dez) Rest: "

    qhex_out: .asciiz "(hex) Quotient: "
    rhex_out: .asciiz "(hex) Rest: "

    xfloat_out: .asciiz "(float) x: "
    yfloat_out: .asciiz "(float) y: "

    xIEEE_out: .asciiz "(IEEE) x: "
    yIEEE_out: .asciiz "(IEEE) y: "    

    zfloat_out: .asciiz "(float) z: "
    zIEEE_out: .asciiz "(IEEE) z: "  

.text

    #m: t0
    #n: t1
    #q: t2
    #r: t3
    #x: f0
    #y: f1
    #x IEEE: t4
    #y IEEE: t5
    #z float: f2
    #z IEEE: t6



    li $v0, 4
    la $a0, m_info
    syscall

    li $v0, 5
    syscall
    move $t0, $v0


    li $v0, 4
    la $a0, n_info
    syscall

    li $v0, 5
    syscall
    move $t1, $v0


    li $v0, 4
    la $a0, m_hex
    syscall
    li $v0, 34
    move $a0, $t0
    syscall
    li $v0, 4
    la $a0, enter_out
    syscall

    li $v0, 4
    la $a0, n_hex
    syscall
    li $v0, 34
    move $a0, $t1
    syscall
    li $v0, 4
    la $a0, enter_out
    syscall

    div $t0, $t1
    mflo $t2
    mfhi $t3


    #Quotient out in dez und hex
    li $v0, 4
    la $a0, q_out
    syscall
    li $v0, 1
    move $a0, $t2
    syscall

    li $v0, 4
    la $a0, enter_out
    syscall

    li $v0, 4
    la $a0, qhex_out
    syscall
    li $v0, 34
    move $a0, $t2
    syscall
    
    li $v0, 4
    la $a0, enter_out
    syscall
    
    #Rest out in dez und hex
    li $v0, 4
    la $a0, r_out
    syscall
    li $v0, 1
    move $a0, $t3
    syscall

    li $v0, 4
    la $a0, enter_out
    syscall

    li $v0, 4
    la $a0, rhex_out
    syscall
    li $v0, 34
    move $a0, $t3
    syscall
    
    li $v0, 4
    la $a0, enter_out
    syscall



    #x to float & IEEE

    #float
    mtc1 $t2, $f0
    cvt.s.w $f0, $f0

    li $v0, 4
    la $a0, xfloat_out
    syscall

    li $v0, 2
    mov.s $f12, $f0
    syscall

    li $v0, 4
    la $a0, enter_out
    syscall

    #IEEE
    li $v0, 4
    la $a0, xIEEE_out
    syscall

    mfc1 $t4, $f0
    li $v0, 34
    move $a0, $t4
    syscall

    li $v0, 4
    la $a0, enter_out
    syscall

    #y to IEEE

    mtc1 $t3, $f1
    cvt.s.w $f1, $f1

    li $v0, 4
    la $a0, yfloat_out
    syscall

    li $v0, 2
    mov.s $f12, $f1
    syscall

    li $v0, 4
    la $a0, enter_out
    syscall

    #IEEE
    li $v0, 4
    la $a0, yIEEE_out
    syscall

    mfc1 $t4, $f1
    li $v0, 34
    move $a0, $t4
    syscall

    li $v0, 4
    la $a0, enter_out
    syscall


    
    #z float div
    li $v0, 4
    la $a0, zfloat_out
    syscall

    div.s $f2, $f1, $f0
    li $v0, 2
    mov.s $f12, $f2
    syscall

    li $v0, 4
    la $a0, enter_out
    syscall


    #z IEEE out
    li $v0, 4
    la $a0, zIEEE_out
    syscall

    mfc1 $a0, $f2
    li $v0, 34
    syscall

    li $v0, 4
    la $a0, enter_out
    syscall


    #end
    li $v0, 10
    syscall

