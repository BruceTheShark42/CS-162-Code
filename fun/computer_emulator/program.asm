	org 0x0000
	ld a,7
	ld b,9
	call mul8
	ret
	
; in: a * b
; out:
;	a = a * b
;	if a != 0, b == 0
; destroys:
;	af, bc
mul8:
	or a
	ret z
	ld c,a
	ld a,b
	or a
	ret z
	ld a,0
mul8loop:
	add a,c
	djnz mul8loop
	ret
