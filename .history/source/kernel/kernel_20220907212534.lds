SECTIONS {
    . = 0x00010000;

    .text : {
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    . = 0x200000

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}