COLISION_DETECTION:
	LD	HL,PLAYER1+1 ; Y
	LD	DE,0         ; PLAYER 1
	LD	C,1	     ; if collision,
			     ; change X direction to the right 
	
	LD	IX,BALL
	LD	A,(IX+2)     ; X BALL
			     ; 1 OR 30, RACKET Y
	CP	1	     ; 1st player
	JR	Z,DETECT
	CP	30	     ; 2nd player
	RET	NZ
			     ; if 2nd player fill DE
			     ; with the value to add
	LD	DE,PLAYER2-PLAYER1
	LD	C,$FF	     ; and X changing direction to the left

DETECT: ADD	HL,DE        ; point either to collision
                             ; with 1st or 2nd player

	; If we arrived here X alread matched
	; either to first or 2nd player

	; now try to match X

	; to any of the three position of the racket

	LD	A,(IX+1)     ; Y BALL
	LD	B,A

	LD	A,(HL)
	CP	B
	JR	NZ,SECOND

	; matched to first position of the racket
	; ball will change direction to
	; Y diagonal up and
	; X opposite direction

	LD	A,C
	LD	(BALLVX),A
	LD	A,$FF
	LD	(BALLVY),A
	JR	MATCH

SECOND: INC	A
	CP	B
	JR	NZ,THIRD

	; matched to second/middle position of the racket
	; ball will change direction to
	; the left or right
	; opposite to the player side
	; (from C register earlier on)

	LD	A,C
	LD	(BALLVX),A
	XOR	A
	LD 	(BALLVY),A
	JR	MATCH

THIRD:	INC	A
	CP	B
	JR	NZ,NOT_MATCH

	; matched last position of the racket
	; ball will change direction to
	; Y diagonal down and
        ; X opposite direction

	LD	A,C
	LD	(BALLVX),A
	LD	A,1
	LD	(BALLVY),A

MATCH:
	CALL 	BALLSOUND
	RET
	
NOT_MATCH:
	CALL	RED_BORDER

	CALL	FAILSOUND	

	CALL	YELLOW_BORDER
	RET

