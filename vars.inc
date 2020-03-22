
; seed for "RANDOM" number
SEED	DEFW	0

; Kempston joystick use "lock"
; if 1 can be used
; once it is 0, it cannot
JOY	DEFB	1

; X direction of ball $FF left, 1 right
BALLVX:	DEFB	0	; VX
; Y direction of ball $FF left, 1 right
BALLVY:	DEFB	0	; VY

; X direction of racket of player 1
; (Filler, never changed)
PLAYER1VX:
	DEFB	0	; VX
; Y direction 
PLAYER1VY:
	DEFB	0	; VY

; X direction of racket of player 2
; (filler, never changed)
PLAYER2VX:
	DEFB	0	; VX
; Y direction
PLAYER2VY:
	DEFB	0	; VY

; Objects for printing from here on
; each has three bytes (CHAR, X, Y)
; if 1st byte of object/CHAR is 0, it ends the list

BEGIN_PRINT:	
; BALL
BALL:	DEFB	$90	; CHAR 
	DEFB	12	; Y
	DEFB	16	; X

; PLAYER 1 Racket
	DEFB	$20	; " "
	DEFB	10	; Y
	DEFB	1	; X
PLAYER1:
        DEFB    $8A     ; CHAR
        DEFB    11      ; Y
        DEFB    1       ; X

	DEFB	$8A	; CHAR
	DEFB	12	; Y
	DEFB	1	; X

        DEFB    $8A     ; CHAR
        DEFB    13      ; Y
        DEFB    1       ; X

	DEFB	$20	; " "
	DEFB	14	; Y
	DEFB	1	; X


; PLAYER 2
	DEFB	$20	; " "
	DEFB	10	; Y
	DEFB	30	; X
PLAYER2:
        DEFB    $85     ; CHAR
        DEFB    11      ; Y
        DEFB    30      ; X
	DEFB	$85	; CHAR
	DEFB	12	; Y
	DEFB	30	; X
        DEFB    $85     ; CHAR
        DEFB    13      ; Y
        DEFB    30      ; X
	DEFB	$20	; " "
	DEFB	14	; Y
	DEFB	30	; X

; SCORE player 1
SCORE1:	
	DEFB	"0"
	DEFB	0	; Y
	DEFB	10	; X

; SCORE player 2
SCORE2:	
	DEFB	"0"
	DEFB	0	; Y
	DEFB	20	; X

; central separator

	DEFB	"|"
	DEFB	1
	DEFB	15

	DEFB	"|"	
	DEFB	3	; Y
	DEFB	15	; X

	DEFB	"|"	
	DEFB	5	; Y
	DEFB	15	; X
	
	DEFB	"|"	
	DEFB	7	; Y
	DEFB	15

	DEFB	"|"	
	DEFB	9	; Y
	DEFB	15	; X

	DEFB 	"|"	
	DEFB	11
	DEFB	15

	DEFB	"|"
	DEFB	13
	DEFB	15

	DEFB	"|"
	DEFB	15
	DEFB	15

	DEFB	"|"
	DEFB	17
	DEFB	15
	
	DEFB	"|"
	DEFB	19
	DEFB	15

	DEFB	"|"
	DEFB	21
	DEFB	15

	DEFB	0

; beggining of WON_MSG string
WON_MSG:	
	DEFB	$16, 10, 1	
	DEFB "PLAYER "

PLAYER_NUM:	
	DEFB "x"

	DEFB " WON.", $0D
	DEFB " PRESS ANY KEY TO CONTINUE.",0

; end of WON_MSG string

