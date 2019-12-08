init:
	; gcc will nicely put the contents of crtend.o's .init section here. */
	pop ebp
	ret

fini:
	; gcc will nicely put the contents of crtend.o's .fini section here. */
	pop ebp
	ret