

.text
    #MMIO standart adresse
    lui     $t0, 0xFFFF
    # 0($0) = Tastaturstatus-register
    # 4($0) = Tastaturdaten-register
    # 12($0) = Displaydaten-register

loop:
    lw      $t1, 0($t0)       # Tastaturstatus bei 0($0) lesen
    andi    $t1, $t1, 1       # check den LSB, wenn true, liegt ein char bereit,
    beq     $t1, $zero, loop  # wenn nicht, back zu loop

    lw      $t2, 4($t0)       # load char aus tastaturdaten-register

    #-----------------Prüfen ob 'a' <= $t2 <= 'z'
    # a = 97 => is 97 <= $t2
    addi    $t3, $zero, 97
    slt     $t4, $t2, $t3     
    bne     $t4, $zero, skip_uppercase

    # a = 97 => is $t2 <= 122
    addi    $t3, $zero, 122
    slt     $t4, $t3, $t2     
    bne     $t4, $zero, skip_uppercase
    #-----------------

    # In Großbuchstabe umwandeln (a - A = 32)
    addi    $t2, $t2, -32

    skip_uppercase:
    sw      $t2, 12($t0)      # char zu Displaydaten-register
    j       loop
