	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC1:
	.ascii "3.5+5.2\0"
.LC2:
	.ascii "%s= %f\12\0"
.LC5:
	.ascii "%d + %d =%d\12\0"
.LC6:
	.ascii "%f + %f =%f\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movq	.LC0(%rip), %rax
	movq	%rax, %rcx
	movq	%rax, %rdx
	movq	%rcx, %rax
	movq	%rdx, %xmm0
	movq	%rax, %xmm2
	movq	%xmm0, %r8
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
	movsd	.LC3(%rip), %xmm0
	movq	.LC4(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	add
	cvttsd2si	%xmm0, %eax
	movl	%eax, %r9d
	movl	$5, %r8d
	movl	$3, %edx
	leaq	.LC5(%rip), %rcx
	call	printf
	movsd	.LC3(%rip), %xmm0
	movq	.LC4(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	add
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%rdx, %r8
	movq	%rax, %xmm1
	movq	.LC3(%rip), %rax
	movq	%rax, %rdx
	movq	%rdx, %rcx
	movq	%rax, %xmm0
	movq	.LC4(%rip), %rax
	movq	%rax, %rdx
	movq	%r8, %xmm3
	movq	%xmm1, %r9
	movq	%rcx, %xmm2
	movq	%xmm0, %r8
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rcx
	call	printf
	movsd	.LC7(%rip), %xmm0
	movq	.LC8(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	add
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%rdx, %r8
	movq	%rax, %xmm1
	movq	.LC7(%rip), %rax
	movq	%rax, %rdx
	movq	%rdx, %rcx
	movq	%rax, %xmm0
	movq	.LC8(%rip), %rax
	movq	%rax, %rdx
	movq	%r8, %xmm3
	movq	%xmm1, %r9
	movq	%rcx, %xmm2
	movq	%xmm0, %r8
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	1717986918
	.long	1075930726
	.align 8
.LC3:
	.long	0
	.long	1075052544
	.align 8
.LC4:
	.long	0
	.long	1074266112
	.align 8
.LC7:
	.long	-858993459
	.long	1075104972
	.align 8
.LC8:
	.long	0
	.long	1074528256
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	add;	.scl	2;	.type	32;	.endef
