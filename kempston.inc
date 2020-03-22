
READ_KEMPSTON:
	IN	A,($1f)
	LD	C,A
	AND	$60
	JR	NZ,KEND	; NO KEMPSTON

	LD	A,C
	AND	$81	; ANY fire pressed
	JR	KPLAYER2 ; controls 2nd player

; ===================== 1st player controls ===============
	LD	A,C
	AND	$08	; UP
	JR	Z,KDOWN
	CALL	RACKET1_UP
	JR	KEND

KDOWN:	
	LD	A,C
	AND	$04	; DOWN
	JR	Z,KEND
	CALL	RACKET1_DOWN
	JR	KEND
; ================= end of 1st player controls ============

; ================ 2nd player controls ===================

KPLAYER2:
	LD      A,C
	AND     $08     ; UP
	JR      Z,KDOWN2
	CALL    RACKET2_UP
	JR      KEND

KDOWN2:
	LD      A,C
	AND     $04     ; DOWN
	JR      Z,KEND
	CALL    RACKET2_DOWN

; ================ end of 2nd player controls ==============

KEND:
	RET

