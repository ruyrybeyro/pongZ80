
	ORG	50000
	CALL	INIT_GAME
	CALL	INIT_BALL
LOOP:	HALT
	HALT
	CALL	READ_KEYS
	CALL	READ_KEMPSTON
	CALL	BALL_MOVE
	CALL	PRINT_CYCLE
	CALL	COLISION_DETECTION
	JR	LOOP
;	CALL	CLOSE_GAME
	RET

	INCLUDE	equ.inc
	INCLUDE	init.inc
	INCLUDE	close.inc
	INCLUDE	ball.inc
	INCLUDE players.inc
	INCLUDE	collision.inc
	INCLUDE	score.inc
	INCLUDE	print.inc
	INCLUDE	keyboard.inc
	INCLUDE kempston.inc
	INCLUDE	beeper.inc
	INCLUDE	colour.inc
	INCLUDE	vars.inc
	INCLUDE	udg.inc

	END	50000
