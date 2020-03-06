	nop
	ld a,13
	ld b,7
	call mul8
	ret
	
; in: a * b
; out:
;	a = a * b
;	if a != 0, b == 0
; destroys:
;	af, bc
mul8:
	or a ; checks if a == 0
	ret z
	ld c,a
	ld a,b
	or a ; checks if b == 0
	ret z
	ld a,0
mul8loop: ; add c to a b times
	add a,c
	djnz mul8loop
	ret
