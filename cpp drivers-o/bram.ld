MEMORY
{
    BRAM (RWX) : ORIGIN = 0x0000, LENGTH = 0x19000  /* kB RAM */
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        *(.text)         /* All .text sections from all files */
        *(.text*)        /* .text* sections (e.g. .text.startup) */
        *(.gnu.linkonce.t.*)
        *(.plt)          /* Procedure Linkage Table */
        *(.init)         /* Initialization code */
        *(.fini)         /* Finalization code */
        KEEP(*(.init))   /* Ensure that .init is not discarded */
        KEEP(*(.fini))   /* Ensure that .fini is not discarded */
        KEEP(*(.ctors))  /* Constructors */
        KEEP(*(.dtors))  /* Destructors */
        *(.eh_frame)     /* Exception handling frames */
        KEEP(*(.eh_frame)) /* Ensure .eh_frame is not discarded */
        _etext = .;      /* End of code section */
    } > BRAM

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)       /* Read-only data */
        *(.rodata*)      /* Read-only data (e.g. .rodata.str1.1) */
        *(.gnu.linkonce.r.*)
        _erodata = .;    /* End of read-only data section */
    } > BRAM

    .data : AT(_erodata)
    {
        . = ALIGN(4);
        _data = .;       /* Start of data section */
        *(.data)         /* Read-write data */
        *(.data*)        /* Read-write data (e.g. .data.rel) */
        *(.gnu.linkonce.d.*)
        _edata = .;      /* End of data section */
    } > BRAM

    .bss :
    {
        . = ALIGN(4);
        _bss_start = .;  /* Start of BSS section */
        *(.bss)          /* Uninitialized data */
        *(.bss*)         /* Uninitialized data (e.g. .bss.rel) */
        *(.gnu.linkonce.b.*)
        *(COMMON)
        _end = .;        /* End of BSS section */
    } > BRAM

    /DISCARD/ :
    {
        *(.comment)      /* Discard comments */
        *(.note.GNU-stack) /* Discard GNU stack note */
    }

    /* Catch-all for any other sections */
    everything :
    {
        . = ALIGN(4);
        *(.everything)   /* Custom section if needed */
        *(.*)
    } > BRAM
}

/* Define symbols for the C runtime initialization */
PROVIDE(__global_pointer$ = 0);
PROVIDE(__bss_start = _bss_start);
PROVIDE(_end = _end);

