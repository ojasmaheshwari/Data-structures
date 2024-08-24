	.file	"main.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.globl	main
	.type	main, @function
main:
.LFB2012:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2012
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZN12DynamicArrayC1Ev@PLT
.LEHE0:
	leaq	-80(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
.LEHB1:
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$2, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$5, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$6, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$7, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$9, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray4pushEi@PLT
	leaq	-80(%rbp), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_ZN12DynamicArray8removeAtEi@PLT
	leaq	-64(%rbp), %rax
	leaq	-80(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNK12DynamicArray8toStringB5cxx11Ev@PLT
.LEHE1:
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
.LEHB2:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE2:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
.LEHB3:
	call	_ZNK12DynamicArray4sizeEv@PLT
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movq	%rax, %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK12DynamicArray8capacityEv@PLT
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZNSolsEi@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE3:
	movl	$0, %ebx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN12DynamicArrayD1Ev@PLT
	movl	%ebx, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L6
	jmp	.L9
.L8:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L4
.L7:
	movq	%rax, %rbx
.L4:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN12DynamicArrayD1Ev@PLT
	movq	%rbx, %rax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	movq	%rax, %rdi
.LEHB4:
	call	_Unwind_Resume@PLT
.LEHE4:
.L9:
	call	__stack_chk_fail@PLT
.L6:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2012:
	.section	.gcc_except_table,"a",@progbits
.LLSDA2012:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2012-.LLSDACSB2012
.LLSDACSB2012:
	.uleb128 .LEHB0-.LFB2012
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB2012
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L7-.LFB2012
	.uleb128 0
	.uleb128 .LEHB2-.LFB2012
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L8-.LFB2012
	.uleb128 0
	.uleb128 .LEHB3-.LFB2012
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L7-.LFB2012
	.uleb128 0
	.uleb128 .LEHB4-.LFB2012
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE2012:
	.text
	.size	main, .-main
	.section	.rodata
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.globl	__gxx_personality_v0
	.ident	"GCC: (GNU) 14.2.1 20240805"
	.section	.note.GNU-stack,"",@progbits
