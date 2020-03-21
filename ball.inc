INIT_BALL:
	LD	IX,BALL
	LD	(IX+1),12	; Y
	LD	(IX+2),16	; X

	; random direction
	LD	HL,(SEED)
	LD	A,(HL)
	INC	HL
	LD	(SEED),HL
	AND	1
	CP	0		; if not right
				; (1 == right)
	JR	NZ,NRANDX
	LD	A,$FF		; left
NRANDX:	LD	(BALLVX),A

	XOR	A		; no vertical
	LD	(BALLVY),A	; on first ball move
NLEAVE:	RET

BALL_MOVE:
	; print space in current position
	LD	IX,BALL
	CALL	GOTOYX
	LD	A,$20
	RST	$10

	; calculate new postion
	; and print ball

; =========================== X HANDLING =============================

	LD	A,(IX+2)	; X
        CP      31		; has it gone over right limit?
        JR      NZ,NOT_LEFT
				; if it has
				; increment score 
	LD	IX,SCORE1	; of first player
	LD	A,"1"		
	LD	(PLAYER_NUM),A
	JP	INC_SCORE
NOT_LEFT:
	CP	0		; has ti gone over left limit?
	JR	NZ,NOT_RIGHT
				; if it has
				; increment score
	LD	IX,SCORE2	; of second player
	LD	A,"2"		
	LD	(PLAYER_NUM),A
	JP	INC_SCORE
NOT_RIGHT:
	LD	B,A

	LD	A,(BALLVX)
	ADD	A,B
	LD	(IX+2),A	; update BALL X position
				; + (BALLVX)

; ============== END X HANDLING ===========================

; ============== Y HANDLING ===============================
	
	LD	A,(IX+1)	; Y position
	LD	B,A
	CP	0
	JR	NZ,NOT_TOP	; crossed top
	LD	A,1		; Y direction
	LD	(BALLVY),A	; change to increment (go down)
	JR	NOT_BOTTOM
NOT_TOP:
	CP	21		; crossed bottom
	JR	NZ,NOT_BOTTOM
	LD	A,$FF		; Y direction
	LD	(BALLVY),A	; change to decrement (go up)
NOT_BOTTOM:
	LD	A,(BALLVY)	; add direction
	LD	B,A
	LD	A,(IX+1)	; to Y position
	ADD	A,B		
	LD	(IX+1),A	; and store it 

; ============== END Y HANDLING -=========================

BLEAVE:	RET

