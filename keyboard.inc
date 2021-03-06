
KEYS_RELEASED:
	XOR 	A
 	IN 	A, ($FE)
 	OR 	224
 	INC 	A
 	JR 	NZ,KEYS_RELEASED
 	RET

KEY_PRESSED:
	XOR 	A                        ; A = 0
 	IN 	A, (254)
 	OR 	224
 	INC 	A
 	JR 	Z,KEY_PRESSED
 	RET

READ_KEYS:
	; Q
	LD	BC,$FBFE
	IN	A,(C)
	AND	1
	JR	NZ,NO_Q
	CALL	RACKET1_UP
	JR	NO_A

NO_Q:	; A
	LD	BC,$FDFE
	IN	A,(C)
	AND	1
	JR	NZ,NO_A
	CALL	RACKET1_DOWN

NO_A:	; O
	LD	BC,$DFFE
	IN	A,(C)
	AND	2
	JR	NZ,NO_O
	CALL	RACKET2_UP
	JR	KEY_END

NO_O:	; L
	LD	BC,$BFFE
	IN	A,(C)
	AND	2
	JR	NZ,KEY_END
	CALL	RACKET2_DOWN
KEY_END:
	RET

