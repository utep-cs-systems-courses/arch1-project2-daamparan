	.arch msp430g2553

	
	.data 			;next is a static variable
n:	.word 0 		;storecs the beginning case

	.text			;Jump Table will be stored
jt:
	.word option1		;turn on LED green and red go to the next case jt[0]
	.word option2		;turn on LED red only go to next case jt[1]
	.word option3		;turn off both LEDS jt[2]
	.word option4		;turn on LED red jt[3]

	;; now we are going to run the selector
	.global state0	
state0:
	mov.b #1, &green_on
	mov &n, r12 		;first we'll move to a temp for 0ease
	cmp #4, r12		;wont borrow if the number isnt more than 4 (# of cases)

	;; now we will index the jump table to know where we are going

	add r12, r12		;2*s to find the index we are in
	mov jt(r12), r0		;move to the place certain case

	;;switch cases
	;; as ordered in JT
	
end:
	jmp state0
	pop r0
	
option1:
	mov.b #1, &green_on	;turns on our green LED
	mov.b #1, &red_on		;turns on our red LED
	mov #1, &n		;puts a new value to our next value
	jmp end		;to end 

option2:
	mov.b #0, &green_on	;turns off our green LED
	mov #2, &n		;indicates our next state
	jmp end			;break

option3:
	mov.b #0, &red_on	;turn off red LED 
	mov #3, &n		;indicate the next state
	jmp end			;break
	
option4:
	mov.b #1, &red_on	;turn on red led
	mov #0, &n		;now we go back to first state to repeat
	jmp end		;break
