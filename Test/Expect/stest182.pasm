pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_checkit
	mov	_var01, #0
LR__0001
	mov	_var02, ina
	and	_var02, #255
	cmp	_var02, #121 wz
 if_e	jmp	#LR__0002
	cmp	_var02, #89 wz
 if_ne	add	_var01, #1
 if_ne	jmp	#LR__0001
LR__0002
	mov	muldiva_, _var01
	mov	muldivb_, #27
	call	#multiply_
	mov	result1, muldiva_
_checkit_ret
	ret

unsmultiply_
       mov    itmp2_, #0
       jmp    #do_multiply_

multiply_
       mov    itmp2_, muldiva_
       xor    itmp2_, muldivb_
       abs    muldiva_, muldiva_
       abs    muldivb_, muldivb_
do_multiply_
	mov    result1, #0
mul_lp_
	shr    muldivb_, #1 wc,wz
 if_c	add    result1, muldiva_
	shl    muldiva_, #1
 if_ne	jmp    #mul_lp_
       shr    itmp2_, #31 wz
       negnz  muldiva_, result1
multiply__ret
	ret

__lockreg
	long	0
itmp1_
	long	0
itmp2_
	long	0
muldiva_
	long	0
muldivb_
	long	0
ptr___lockreg_
	long	@@@__lockreg
result1
	long	0
COG_BSS_START
	fit	496
	org	COG_BSS_START
_var01
	res	1
_var02
	res	1
	fit	496
