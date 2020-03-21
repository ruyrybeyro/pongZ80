
; sound when player misses the ball
FAILSOUND:
	LD	HL,3000
	LD	B,10
	JP	BEEP

; sound when player intercepts the ball
BALLSOUND:
	LD	HL,500           ; starting pitch.
       	LD	B,1              ; length of pitch bend.

BEEP:  
	PUSH	BC
       	PUSH	HL             	 ; store pitch.
       	LD	DE,1             ; very short duration.
       	CALL	BEEPER           ; ROM beeper routine.
       	POP	HL               ; restore pitch.
       	INC	HL               ; pitch going up.
       	POP	BC
       	DJNZ	BEEP             ; repeat.
       	RET

