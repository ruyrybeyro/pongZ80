; Increment score
; VAR pointed by IX
;
; if 9, print win message
; and start all over again
;
; arrives here each time a player
; misses the ball
;
; e.g. there is no collision between
; the ball and a racket

INC_SCORE: 
	INC	(IX)
        LD	A,(IX)
	CP	"9"
	JR	NZ,GO_GAME

	CALL	KEYS_RELEASED

        CALL    CL_ALL
	LD	IX,WON_MSG
	CALL	PRINT_STRING

	CALL	KEY_PRESSED

	CALL	INIT_GAME
	
GO_GAME:JP	INIT_BALL

