	.global safe_syscall_base
	.global safe_syscall_start
	.global safe_syscall_end
	.type	safe_syscall_base, @function
	.type	safe_syscall_start, @function
	.type	safe_syscall_end, @function

	/*
	 * This is the entry point for making a system call. The calling
	 * convention here is that of a C varargs function with the
	 * first argument an 'int *' to the signal_pending flag, the
	 * second one the system call number (as a 'long'), and all further
	 * arguments being syscall arguments (also 'long').
	 * We return a long which is the syscall's return value, which
	 * may be negative-errno on failure. Conversion to the
	 * -1-and-errno-set convention is done by the calling wrapper.
	 */
safe_syscall_base:
	.cfi_startproc
	/*
	 * The syscall calling convention is nearly the same as C:
	 * we enter with a0 == *signal_pending
	 *               a1 == syscall number
	 *               a2 ... a7 == syscall arguments
	 *               and return the result in v0
	 * and the syscall instruction needs
	 *               v0 == syscall number
	 *               a0 ... a5 == syscall arguments
	 *               and returns the result in v0
	 *               if error flag in a3 is 1(non-zero),
	 *               v0 was neg of error number
	 * Shuffle everything around appropriately.
	 */
	/* just copy and modify from libc syscall */
	daddiu	$sp, $sp, -8
	sd   	$a0, 0($sp)		/* signal_pending pointer */
	move	$v0, $a1		/* syscall number */
	move	$a0, $a2		/* syscall arguments */
	move	$a1, $a3
	move	$a2, $a4
	move	$a3, $a5
	move	$a4, $a6
	move	$a5, $a7

	/*
	 * This next sequence of code works in conjunction with the
	 * rewind_if_safe_syscall_function(). If a signal is taken
	 * and the interrupted PC is anywhere between 'safe_syscall_start'
	 * and 'safe_syscall_end' then we rewind it to 'safe_syscall_start'.
	 * The code sequence must therefore be able to cope with this, and
	 * the syscall instruction must be the final one in the sequence.
	 */
safe_syscall_start:
	/* If signal_pending is non-zero, don't do the call */
	ld	$t0, 0($sp)
	lw	$t1, 0($t0)
	bnez	$t1, 0f
	syscall
safe_syscall_end:
	/* code path for having successfully executed the syscall */
	daddiu	$sp, $sp, 8
	/* if err was set, reverse the return value */
	beqz	$a3, 1f
	dsubu	$v0, $zero, $v0
 1:
	jr $ra
 0:
	/* code path when we didn't execute the syscall */
	li	$v0, -TARGET_ERESTARTSYS
	daddiu	$sp, $sp, 8
	jr $ra
	.cfi_endproc
	.size	safe_syscall_base, .-safe_syscall_base
