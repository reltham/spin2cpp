pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_foo
	rdlong	result1, #0
	add	result1, #2
_foo_ret
	ret

__lockreg
	long	0
ptr___lockreg_
	long	@@@__lockreg
result1
	long	0
COG_BSS_START
	fit	496
	org	COG_BSS_START
	fit	496
