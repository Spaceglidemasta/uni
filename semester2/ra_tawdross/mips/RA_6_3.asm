# Overflow nach 16

.data
    info: .asciiz "Geben Sie eine positive Ganze zahl an: "
    fak: .asciiz "Fakultät: "


.text

    li $v0, 4
    la $a0, info
    syscall
    li $v0, 5
    syscall

    move $a0, $v0     # arg für fakt
    jal fakt    
    move $t1, $v0     

    li $v0, 4
    la $a0, fak
    syscall
    move $a0, $t1
    li $v0, 1         
    syscall

    li $v0, 10      
    syscall

# -------------------------------------
fakt:
    addi $sp, $sp, -8     #allocate
    sw $ra, 4($sp)        
    sw $a0, 0($sp)       

    li $v0, 1             
    ble $a0, $v0, end_fakt

    addi $a0, $a0, -1     
    jal fakt

    lw $a0, 0($sp)        
    mul $v0, $a0, $v0     # v = n - 1, a = n

end_fakt:
    lw $ra, 4($sp)      
    addi $sp, $sp, 8      
    jr $ra                # return adress
