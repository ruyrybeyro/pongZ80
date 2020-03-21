
GREEN_PAPER_YELLOW:
        LD      A,$27           ; INK WHITE - PAPER GREEN
        LD      (ATTR_P),A
        LD      (ATTR_T),A
	RET

YELLOW_BORDER:
        LD      A,6             ; YELLOW
        OUT     ($FE),A         ; BORDER
        RLCA
        RLCA
        RLCA
        XOR     7
        LD      (BORDCR),A      ; save system border
	RET

RED_BORDER:
	LD      A,2
        OUT     ($FE),A         ; red border
	RET

