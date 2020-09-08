# Code:
#0  t4
#1  t5
#2  t3
#3  t4
#4  t2
#5  t6
#6  t6
#7  t7
# .TEXT <showDisplay>
	.text
showDisplay:

# Frame:	$fp, $ra
# Uses:		$s0, $s1, $t3, $t4, $t2
# Clobbers:	$t3, $t4, $t2

# Locals:
#	- `i' in $s0
#	- `j' in $s1

# Structure:
#	showDisplay
#	-> [prologue]
#	-> showDisplay_row
#		-> showDisplay_col
#		-> showDisplay_col_post
#	-> showDisplay_row_post
#	-> [epilogue]

#how to putchar(display[i][j]):
#each char has  9 column in every row
#				9 row
#				81 byte

# Code:
	# set up stack frame
	sw	$fp, -4($sp)
	la	$fp, -4($sp)
	sw	$ra, -4($fp)
	sw	$s0, -8($fp)
	sw	$s1, -12($fp)
	addi	$sp, $sp, -16

	la	$a0, CLEAR
	li	$v0, 4
	syscall					# printf(CLEAR)

	la	$t3, NROWS
	lw	$t3, ($t3)			# $t3 = NROWS
	la	$t4, NDCOLS
	lw	$t4, ($t4)			# $t4 = NDCOLS

	li	$s0, 0				# $s0 = i = 0
showDisplay_row:
	bge	$s0, $t3, showDisplay_row_post# if (i >= NROWS) goto showDisplay_row_post
	li	$s1, 0				# $s1 = j = 0
showDisplay_col:
	bge $s1, $t4, showDisplay_col_post# if (j >= NDCOLS) goto showDisplay_col_post
	mul	$t2, $s0, $t4		# i * NDCOLS
	add $t2, $t2, $s1		# $t2 = offset = i * NDCOLS + j
	lb	$a0, display($t2)
	li	$v0, 11
	syscall					# putchar(display[i][j])
	addi	$s1, $s1, 1		# j++
	j	showDisplay_col
showDisplay_col_post:
	li	$a0, '\n'
	li	$v0, 11
	syscall					# putchar('\n')
	addi	$s0, $s0, 1		# i++
	j	showDisplay_row
showDisplay_row_post:
	# tear down stack frame
	lw	$s1, -12($fp)
	lw	$s0, -8($fp)
	lw	$ra, -4($fp)
	la	$sp, 4($fp)
	lw	$fp, ($fp)
	jr	$ra
	nop	# in delay slot