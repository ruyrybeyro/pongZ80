

RACKET1_UP:
	LD	IX,PLAYER1	; point to player 1
GOUP:	LD	A,(IX+1)
	CP	1
	RET	Z
	DEC	(IX-2)
	DEC	(IX+1)
	DEC	(IX+4)
	DEC	(IX+7)
	DEC	(IX+10)
	RET

RACKET1_DOWN:
	LD	IX,PLAYER1	; point to player 1
GODOWN:	LD	A,(IX+1)
	CP	21-3
	RET	Z
	INC	(IX-2)
	INC	(IX+1)
	INC	(IX+4)
	INC	(IX+7)
	INC	(IX+10)
	RET

RACKET2_UP:
	LD	IX,PLAYER2	; point to player 2
	JR	GOUP

RACKET2_DOWN:
	LD	IX,PLAYER2	; point to player 2
	JR	GODOWN

