	.file	"cs3-61.c"
	.text
	.globl	var_prod_ele
	.type	var_prod_ele, @function
var_prod_ele:
.LFB0:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %ecx
	leal	0(,%ecx,4), %edx
	movl	%edx, %ebx
	imull	28(%esp), %ebx
	addl	20(%esp), %ebx
	movl	32(%esp), %eax
	sall	$2, %eax
	movl	24(%esp), %edi
	addl	%eax, %edi
	movl	%edx, %esi
	movl	$0, %eax
	testl	%edx, %edx
	jle	.L2
	movl	(%edi,%ecx,4), %edi
	movl	$0, %edx
.L3:
	movl	%edi, %ecx
	imull	(%ebx,%edx), %ecx
	addl	%ecx, %eax
	addl	$4, %edx
	cmpl	%edx, %esi
	jg	.L3
.L2:
	popl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 8
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 4
	.cfi_restore 7
	ret
	.cfi_endproc
.LFE0:
	.size	var_prod_ele, .-var_prod_ele
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
