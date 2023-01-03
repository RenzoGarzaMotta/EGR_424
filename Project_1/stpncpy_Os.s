	.syntax unified
	.cpu cortex-m3
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 4
	.eabi_attribute 18, 4
	.thumb
	.file	"stpncpy.c"
	.text
	.align	1
	.global	stpncpy
	.thumb
	.thumb_func
	.type	stpncpy, %function
stpncpy:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, lr}	;Store R4, R5, and LR into the stack in case there are subroutine calls
	mov	r3, r0	;Store dst into R3
	mov	ip, #0	;Store the immediate decimal value of 0 into R12
	b	.L2 ;Branch to .L2
.L5: ;If count is a non-zero value continue
	ldrb	r5, [r1, ip]	@ zero_extendqisi2 ;Load a byte from src address + ip offset into R5
	subs	r2, r2, #1 ;Force conditional flag update. Subtract 1 from count
	strb	r5, [r0, ip] ;store the value from R5 (data from src address + ip offset) into dst (R0) + ip offset
	adds	r4, r3, #1 ;Force conditional flag update. Increase dst by one and store it in R4
	add	ip, ip, #1 ;Increase ip (address offset) by 1
	cbnz	r5, .L3 ;Check if the copied data from src was not a NULL (0) character. If character copied was not NULL, branch to .L3
	mov	r0, r3 ;Store the old dst (R3) into R0
	mov	r3, r4 ;Store the updated dst (R4) into R3 (to prepare for the loop)
.L6:
	mov	r4, r2 ;Store count into R4.
	movs	r1, #0 ;Force conditional flag update. Clear the source address
	b	.L4 ;branch to .L4
.L3:
	mov	r3, r4 ;Store the updated dst (R4) into R3 (to prepare for the loop)
.L2:
	cmp	r2, #0 ;Check if count is zero
	bne	.L5 ;if count is non-zero, branch to .L5 (loop)
	mov	r0, r2 ;If count is zero, store count (0) into R0
	b	.L6 ; branch to .L6
.L7:
	mov	ip, #0 ;clear the ip offset
	strb	ip, [r3, r1] ;  
	subs	r4, r4, #1
	adds	r1, r1, #1
.L4:
	cmp	r4, #0 ;Check if count is zero
	bne	.L7 ;If count is not zero, branch to .L7
	adds	r2, r3, r2 ; add the count (R2) with dst (R3) and store it in R2
	cmp	r0, #0 ;Check if the old dst is zero
	it	eq ;Run an IT Block depending on the state of old dst
	moveq	r0, r2 ;if dst is zero, move count + dist to R0
	pop	{r4, r5, pc} ;balance the stack by popping the data, and allocating is to R4, R5 and PC
	.size	stpncpy, .-stpncpy
	.ident	"GCC: (Sourcery G++ Lite 2010q1-188) 4.4.1"
