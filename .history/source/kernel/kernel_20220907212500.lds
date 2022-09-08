SECTIONS {
    . = 0x00010000;

    .text : {
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    . = 0x20000

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}