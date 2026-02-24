	.file	"Fibonacci.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%lluth Fibonacci Number : \n\n"
.LC1:
	.string	"%d"
	.text
	.p2align 4
	.globl	PrintFibonacci
	.type	PrintFibonacci, @function
PrintFibonacci:
.LFB31:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	leaq	1(%rsi), %rdx
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rsi
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rdi, %rbp
	movl	$1, %edi
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	call	__printf_chk@PLT
	movq	100000000(%rbp), %rdx
	movl	$99999999, %eax
	subl	%edx, %eax
	cmpl	$99999998, %eax
	jg	.L1
	cltq
	leaq	.LC1(%rip), %r12
	leaq	0(%rbp,%rax), %rbx
	leaq	1(%rbp,%rax), %rbp
	leal	-1(%rdx), %eax
	addq	%rax, %rbp
	.p2align 4,,10
	.p2align 3
.L3:
	movzbl	(%rbx), %edx
	movq	%r12, %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	addq	$1, %rbx
	call	__printf_chk@PLT
	cmpq	%rbp, %rbx
	jne	.L3
.L1:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE31:
	.size	PrintFibonacci, .-PrintFibonacci
	.p2align 4
	.globl	CalculateExecutionTime
	.type	CalculateExecutionTime, @function
CalculateExecutionTime:
.LFB32:
	.cfi_startproc
	endbr64
	subq	%rdi, %rsi
	movq	%rsi, -16(%rsp)
	fildq	-16(%rsp)
	fdivs	.LC2(%rip)
	ret
	.cfi_endproc
.LFE32:
	.size	CalculateExecutionTime, .-CalculateExecutionTime
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC4:
	.string	"\n\nUsage: ./Fibonacci [RANGE ...]\n"
	.section	.rodata.str1.1
.LC5:
	.string	"Examples:\n"
.LC6:
	.string	"\tSpecifying range:\n"
	.section	.rodata.str1.8
	.align 8
.LC7:
	.string	"\t\t--range=max\tGenerates the maximum possible fibonacci number that can be generated with the given heap.\n"
	.align 8
.LC8:
	.string	"\t\t--range=N\tGenerates the Nth fibonacci number if enough heap space is available.\n"
	.text
	.p2align 4
	.globl	ShowCommandLineArgumentsHelp
	.type	ShowCommandLineArgumentsHelp, @function
ShowCommandLineArgumentsHelp:
.LFB33:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC5(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC6(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC7(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movl	$1, %edi
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	leaq	.LC8(%rip), %rsi
	jmp	__printf_chk@PLT
	.cfi_endproc
.LFE33:
	.size	ShowCommandLineArgumentsHelp, .-ShowCommandLineArgumentsHelp
	.section	.rodata.str1.1
.LC9:
	.string	"\nUnknown argument: %s"
	.section	.rodata
.LC10:
	.string	"--range="
	.string	""
	.section	.rodata.str1.8
	.align 8
.LC11:
	.string	"\nValue not specified for argument: %s"
	.section	.rodata.str1.1
.LC12:
	.string	"\nInvalid range: %s"
	.text
	.p2align 4
	.globl	ParseRange
	.type	ParseRange, @function
ParseRange:
.LFB34:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movl	$1, %eax
	movq	%rdi, %r12
	movl	$45, %edx
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	leaq	-1+.LC10(%rip), %rsi
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L11:
	movzbl	1(%rsi,%rax), %edx
	movslq	%eax, %rbp
	leaq	1(%rax), %rcx
	testb	%dl, %dl
	je	.L21
	movq	%rcx, %rax
.L13:
	cmpb	%dl, -1(%r12,%rax)
	je	.L11
	movq	%r12, %rdx
	leaq	.LC9(%rip), %rsi
.L20:
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC5(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC6(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC7(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC8(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	$-1, %rax
.L10:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L21:
	.cfi_restore_state
	movsbl	(%r12,%rax), %ebx
	testb	%bl, %bl
	je	.L14
	call	__ctype_b_loc@PLT
	leaq	1(%r12,%rbp), %rdx
	movq	(%rax), %rsi
	xorl	%eax, %eax
	jmp	.L15
	.p2align 4,,10
	.p2align 3
.L16:
	subl	$48, %ebx
	leaq	(%rax,%rax,4), %rax
	addq	$1, %rdx
	movslq	%ebx, %rbx
	leaq	(%rbx,%rax,2), %rax
	movsbl	-1(%rdx), %ebx
	testb	%bl, %bl
	je	.L10
.L15:
	movsbq	%bl, %rcx
	testb	$4, 1(%rsi,%rcx,2)
	je	.L16
	movq	%r12, %rdx
	leaq	.LC12(%rip), %rsi
	jmp	.L20
.L14:
	movq	%r12, %rdx
	leaq	.LC11(%rip), %rsi
	jmp	.L20
	.cfi_endproc
.LFE34:
	.size	ParseRange, .-ParseRange
	.section	.rodata.str1.1
.LC13:
	.string	"--range=max"
	.text
	.p2align 4
	.globl	DecideRange
	.type	DecideRange, @function
DecideRange:
.LFB35:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	.LC13(%rip), %rsi
	movq	%rdi, %rbp
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L23
	movq	%rbp, %rdi
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	jmp	ParseRange
	.p2align 4,,10
	.p2align 3
.L23:
	.cfi_restore_state
	movq	$-1, %rax
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE35:
	.size	DecideRange, .-DecideRange
	.section	.rodata.str1.1
.LC14:
	.string	"\nToo many arguments !"
	.text
	.p2align 4
	.globl	CommandLineValidator
	.type	CommandLineValidator, @function
CommandLineValidator:
.LFB36:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	cmpl	$2, %edi
	je	.L26
	leaq	.LC14(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC5(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC6(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC7(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	leaq	.LC8(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movl	$1, %eax
	xorl	%edx, %edx
.L27:
	andl	$1, %eax
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	.cfi_restore_state
	movq	8(%rsi), %rbp
	leaq	.LC13(%rip), %rsi
	movq	%rbp, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L28
	movq	%rbp, %rdi
	call	ParseRange
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	cmpq	$-1, %rax
	movq	%rax, %rdx
	setne	%al
	andl	$1, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L28:
	.cfi_restore_state
	xorl	%eax, %eax
	movq	$-1, %rdx
	jmp	.L27
	.cfi_endproc
.LFE36:
	.size	CommandLineValidator, .-CommandLineValidator
	.section	.rodata.str1.1
.LC15:
	.string	"clear"
	.section	.rodata.str1.8
	.align 8
.LC16:
	.string	"Possible overflow in next iteration.\nTerminating....\n\n"
	.align 8
.LC17:
	.string	"\n\n\nCalculation Time: %Lf secs\n\n"
	.section	.rodata.str1.1
.LC18:
	.string	"\nInternal Error !"
	.section	.rodata.str1.8
	.align 8
.LC19:
	.string	"\n\nCalculation Time: %Lf secs\n\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB37:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	call	CommandLineValidator
	testb	%al, %al
	je	.L47
	leaq	fibonacci(%rip), %rbx
	leaq	.LC15(%rip), %rdi
	movq	%rdx, %rbp
	movl	%eax, %r15d
	call	system@PLT
	movl	$99999999, %edx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	memset@PLT
	leaq	100000008(%rbx), %rdi
	movl	$99999999, %edx
	xorl	%esi, %esi
	call	memset@PLT
	leaq	200000016(%rbx), %rdi
	movl	$99999999, %edx
	xorl	%esi, %esi
	call	memset@PLT
	call	clock@PLT
	movq	%rax, (%rsp)
	leaq	-1(%rbp), %rax
	movq	%rax, 8(%rsp)
	testq	%rax, %rax
	jle	.L32
	xorl	%r12d, %r12d
	xorl	%r8d, %r8d
	movl	$99999999, %r13d
	movl	$-51, %r11d
	movl	$99999998, %r10d
.L40:
	movq	%r12, %rax
	leaq	1(%r12), %r14
	leaq	2(%r12), %rbp
	movabsq	$-6148914691236517205, %rcx
	mulq	%rcx
	movq	%r14, %rax
	movq	%rdx, %r9
	andq	$-2, %rdx
	shrq	%r9
	addq	%r9, %rdx
	movq	%r12, %r9
	subq	%rdx, %r9
	mulq	%rcx
	movq	%rbp, %rax
	movq	%rdx, %rdi
	andq	$-2, %rdx
	shrq	%rdi
	addq	%rdi, %rdx
	movq	%r14, %rdi
	subq	%rdx, %rdi
	mulq	%rcx
	movq	%rdx, %rsi
	andq	$-2, %rdx
	shrq	%rsi
	addq	%rsi, %rdx
	movq	%rbp, %rsi
	subq	%rdx, %rsi
	imulq	$100000008, %rdi, %rdx
	imulq	$100000008, %rsi, %rbp
	addq	%rbx, %rdx
	movq	100000000(%rdx), %rax
	addq	%rbx, %rbp
	movq	%rax, 100000000(%rbp)
	testb	%r15b, %r15b
	je	.L33
	imulq	$100000008, %r9, %rax
	addq	%rbx, %rax
	movq	$1, 100000000(%rax)
	movb	$0, 99999998(%rax)
	movl	$1, %eax
	movq	$1, 100000000(%rdx)
	movb	$1, 99999998(%rdx)
	movq	$1, 100000000(%rbp)
.L34:
	imulq	$100000008, %r9, %r9
	movl	$99999998, %ecx
	imulq	$100000008, %rdi, %rdi
	imulq	$100000008, %rsi, %rsi
	addq	%rbx, %r9
	addq	%rbx, %rdi
	addq	%rbx, %rsi
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L38:
	movq	100000000(%rsi), %rax
	movq	%r10, %rdx
	subq	$1, %rcx
	subq	%rax, %rdx
	cmpq	%rcx, %rdx
	jge	.L35
.L39:
	movzbl	(%rdi,%rcx), %edx
	addb	(%r9,%rcx), %dl
	addl	%r8d, %edx
	xorl	%r8d, %r8d
	cmpb	$9, %dl
	jbe	.L36
	movq	%r13, %r8
	subq	100000000(%rdi), %r8
	cmpq	%rcx, %r8
	jne	.L37
	addq	$1, %rax
	movq	%rax, 100000000(%rsi)
.L37:
	movl	%edx, %eax
	movl	$1, %r8d
	mulb	%r11b
	shrw	$11, %ax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %edx
.L36:
	movb	%dl, 0(%rbp,%rcx)
	cmpb	$0, (%rsi)
	je	.L38
	leaq	.LC16(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	%r12, %rsi
	movq	%rbp, %rdi
	call	PrintFibonacci
	call	clock@PLT
	subq	(%rsp), %rax
	subq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 96
	movl	$1, %edi
	movq	%rax, 16(%rsp)
	fildq	16(%rsp)
	leaq	.LC17(%rip), %rsi
	xorl	%eax, %eax
	fdivs	.LC2(%rip)
	fstpt	(%rsp)
	call	__printf_chk@PLT
	xorl	%edi, %edi
	call	exit@PLT
	.p2align 4,,10
	.p2align 3
.L33:
	.cfi_restore_state
	movq	%r10, %rdx
	subq	%rax, %rdx
	cmpq	$99999997, %rdx
	jle	.L34
	.p2align 4,,10
	.p2align 3
.L35:
	xorl	%r15d, %r15d
	cmpq	8(%rsp), %r14
	je	.L48
	movq	%r14, %r12
	jmp	.L40
.L48:
	call	clock@PLT
	movq	%r14, %rsi
	movq	%rbp, %rdi
	movq	%rax, %rbx
	call	PrintFibonacci
	subq	(%rsp), %rbx
	movl	$1, %edi
	leaq	.LC19(%rip), %rsi
	movq	%rbx, (%rsp)
	fildq	(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 88
	fdivs	.LC2(%rip)
	pushq	%rax
	.cfi_def_cfa_offset 96
	xorl	%eax, %eax
	fstpt	(%rsp)
	call	__printf_chk@PLT
	addq	$40, %rsp
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L32:
	.cfi_def_cfa_offset 80
	call	clock@PLT
	leaq	.LC18(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
.L47:
	movl	$1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE37:
	.size	main, .-main
	.globl	fibonacci
	.bss
	.align 32
	.type	fibonacci, @object
	.size	fibonacci, 300000024
fibonacci:
	.zero	300000024
	.globl	commandLineValidationResult
	.align 16
	.type	commandLineValidationResult, @object
	.size	commandLineValidationResult, 16
commandLineValidationResult:
	.zero	16
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC2:
	.long	1232348160
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
