.global fabsf
.type fabsf,@function
fabsf:
	.cfi_startproc
	mov $0x7fffffff,%eax
	movq %rax,%xmm1
	andps %xmm1,%xmm0
	ret
	.cfi_endproc
