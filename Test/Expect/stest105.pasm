pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_swapab
	add	objptr, #4
	rdlong	_var01, objptr
	sub	objptr, #4
	rdlong	_var02, objptr
	wrlong	_var01, objptr
	add	objptr, #4
	wrlong	_var02, objptr
	sub	objptr, #4
_swapab_ret
	ret

_seq3
	mov	result2, arg01
	add	result2, #1
	mov	result3, arg01
	add	result3, #2
	mov	result1, arg01
_seq3_ret
	ret

_setit1
	mov	arg01, #1
	call	#_seq3
	wrlong	result1, objptr
	add	objptr, #4
	wrlong	result2, objptr
	add	objptr, #4
	wrlong	result3, objptr
	sub	objptr, #8
_setit1_ret
	ret

_setit2
	mov	arg01, #0
	call	#_seq3
	wrlong	result1, objptr
	add	objptr, #4
	wrlong	result2, objptr
	add	objptr, #4
	wrlong	result3, objptr
	sub	objptr, #8
_setit2_ret
	ret

__lockreg
	long	0
objptr
	long	@@@objmem
ptr___lockreg_
	long	@@@__lockreg
result1
	long	0
result2
	long	0
result3
	long	0
COG_BSS_START
	fit	496
objmem
	long	0[3]
	org	COG_BSS_START
_var01
	res	1
_var02
	res	1
arg01
	res	1
	fit	496
