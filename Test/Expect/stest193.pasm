pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_hang
LR__0001
	jmp	#LR__0001
_hang_ret
	ret

_wait
	mov	_var01, #1
	shl	_var01, arg01
LR__0002
	test	ina, _var01 wc
 if_ae	jmp	#LR__0002
_wait_ret
	ret

__lockreg
	long	0
ptr___lockreg_
	long	@@@__lockreg
COG_BSS_START
	fit	496
	org	COG_BSS_START
_var01
	res	1
arg01
	res	1
	fit	496
