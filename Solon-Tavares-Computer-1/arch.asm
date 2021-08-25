	NOP
	INR
	ADD 10h	; ACC = ACC + B_REG(10h)
	OUT
	STA 10h	; (10h) = ACC
	JMP 01h	; PC = 01h
	HLT
	00h