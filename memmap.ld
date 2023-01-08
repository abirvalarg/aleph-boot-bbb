EXTERN(vectors)

MEMORY {
    ram (rwx) : ORIGIN = 0x402F0400, LENGTH = 109K
}

SECTIONS {
    .text : {
        KEEP(*(.text.vectors))
        *(.text*)
    } > ram

    .data : {
        *(.rodata*)
        *(.data*)
    } > ram
}
