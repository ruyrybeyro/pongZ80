

FAILSOUND:
	LD	HL,3000
	LD	B,10
	JP	BEEP

BALLSOUND:
	LD	HL,500           ; starting pitch.
       	LD	B,1              ; length of pitch bend.

BEEP:  
SLOOP:	PUSH	BC
       	PUSH	HL             	 ; store pitch.
       	LD	DE,1             ; very short duration.
       	CALL	BEEPER           ; ROM beeper routine.
       	POP	HL               ; restore pitch.
       	INC	HL               ; pitch going up.
       	POP	BC
       	DJNZ	SLOOP            ; repeat.
       	RET

