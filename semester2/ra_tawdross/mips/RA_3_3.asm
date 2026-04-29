.data
	frage: .asciiz "Geben Sie das zu prüfende Jahr ein: "
	
	ja: .asciiz "Ja, "
	ein: .asciiz " ist ein Schaltjahr."

	nein: .asciiz "Nein, "
	kein: .asciiz " ist kein Schaltjahr."
	
.text
	la $a0, frage
	li $v0, 4
	syscall

	li $v0, 5
	syscall
	move $t0, $v0


	li $t2, 4
	div $t0, $t2 #q zu LO, r zu HI
	mfhi $t1


	beq $t1, 0, true
	j false

	true:
		la $a0, ja
		li $v0, 4
		syscall

		move $a0, $t0
		li $v0, 1
		syscall

		la $a0, ein
		li $v0, 4
		syscall
		
		li $v0 10 #exit
		syscall


	false:
		la $a0, nein
		li $v0, 4
		syscall

		move $a0, $t0
		li $v0, 1
		syscall

		la $a0, kein
		li $v0, 4
		syscall

	
