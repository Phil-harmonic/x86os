/**
 *
 * 
 */
  	.code16
 	.text
	.global _start
	.extern loader_entry
_start:
	jmp loader_entry

	.code32
	.text
protect_mode_entry:
	jmp .