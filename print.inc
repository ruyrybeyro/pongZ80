
; print objects of screen present in memory
; each object 3 bytes
; 1st - CHAR
; 2nd - Y position
; 3nd - X position
;
; if 1st/CHAR is 0, routine ends printing objects
; (0 marker of end of "array")
;
PRINT_CYCLE:
	LD	IX,BEGIN_PRINT
PCYCLE:	LD	A,(IX)
	CP	0
	RET	Z
	CALL	GOTOYX
	LD	A,(IX)
	RST	$10
	INC	IX
	INC	IX
	INC	IX
	JR	PCYCLE

; move text cursor
; to (Y,X) postion

GOTOYX:	LD	A,$16
	RST	$10
	LD      A,(IX+1)	; Y
	RST	$10
	LD	A,(IX+2)	; X
	RST	$10
	RET

; PRINT STRING POINTED BY IX
; ENDED BY 0

PRINT_STRING:
	LD	A,(IX)
	CP	0
	RET	Z
	RST	$10
	INC	IX
	JR	PRINT_STRING

