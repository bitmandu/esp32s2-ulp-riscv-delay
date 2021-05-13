.section .text.wait

.global wait
.type wait, @function

wait:
	beq a0, zero, end
	addi a0, a0, -1
	j wait

end:
	ret
