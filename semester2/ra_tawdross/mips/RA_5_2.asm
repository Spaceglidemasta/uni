.data
    info: .asciiz "Geben Sie eine postive ganze Zahl ein: "
    sum: .asciiz "Summe aller geraden Zahlen: "


.text
	
    #t0: Summe
    #t1: i - 1

    #t4: 2
    #t5: 1


    li $v0, 4
    la $a0, info
    syscall
    li $v0, 5
    syscall

    move $t0, $v0
    move $t1, $t0 

    li $t5, 1
    li $t4, 2 


    loop:

        sub $t1, $t1, $t5
        
        div $t1, $t4
        mfhi $t3

        bne $t3, $zero, skip

        add $t0, $t0, $t1 

        skip:
        
    bne $t1, $zero, loop
    j end

    end:
    
    li $v0, 4
    la $a0, sum
    syscall

    li $v0, 1
    move $a0, $t0
    syscall
    
	
