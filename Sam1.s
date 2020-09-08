# CP1521 Final Exam Q1

   .text
   .globl toLower

#void toLower(char * src){	
#	while(*src != '\0'){
#		if(*src >= 'A' && *src <='Z'){
#			*src = *src + ('a' - 'A');
#		}
#		src++;
#	}
#}
 
 
# Input registers: src  $a0

toLower:
# prologue
   addi $sp, $sp, -4
   sw   $fp, ($sp)
   la   $fp, ($sp)
   addi $sp, $sp, -4
   sw   $ra, ($sp)
   addi $sp, $sp, -4
   sw   $s0, ($sp)
   addi $sp, $sp, -4
   sw   $s1, ($sp)
   addi $sp, $sp, -4
   sw   $s2, ($sp)
   # if you need to save more $s? registers
   # add the code to save them here

# function body
# locals: ...
while_loop:
    lb      $s0, ($a0)                  # s0 = *src
    li      $t0, 0                      # t0 = '\0' = 0
    beq     $s0, $t0, while_loop_end    # while condition
    # in to if
    li      $t0, 'A'                    # t0 = 'A'
    li      $t1, 'Z'                    # t1 = 'Z'

if_A:
    blt     $s0, $t0, if_end            # *src >= 'A'

if_Z:
    bgt     $s0, $t1, if_end            # *src <='Z'

    li      $t2, 'a'
    sub     $t2, $t2, $t0               # 'a' - 'A'
    add     $s0, $s0, $t2               #  *src = *src + ('a' -'A')
    sb      $s0, ($a0)

if_end:
    addi    $a0, $a0, 1
    j       while_loop

while_loop_end:

# epilogue
   # if you saved more than three $s? registers
   # add the code to restore them here
   lw   $s2, ($sp)
   addi $sp, $sp, 4
   lw   $s1, ($sp)
   addi $sp, $sp, 4
   lw   $s0, ($sp)
   addi $sp, $sp, 4
   lw   $ra, ($sp)
   addi $sp, $sp, 4
   lw   $fp, ($sp)
   addi $sp, $sp, 4
   j    $ra
