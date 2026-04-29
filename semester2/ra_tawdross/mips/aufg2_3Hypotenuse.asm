
.data

	kata: .asciiz "Geben Sie die länge von Kathete a an: "
	katb: .asciiz "Geben Sie die länge von Kathete b an: "
	text: .asciiz "Das Quadrat der Hypotenuse ist: "


.text

	li $v0, 4
	la $a0, kata
	syscall
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 4
	la $a0, katb
	syscall
	li $v0, 5
	syscall
	move $t1, $v0
	
	
	mulu $t0, $t0, $t0
	mulu $t1, $t1, $t1
	
	add $t2, $t1, $t0
	

	li $v0, 4
	la $a0, text
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	