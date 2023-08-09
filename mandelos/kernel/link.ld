OUTPUT_FORMAT(elf32-i386)
SECTIONS
 {
   . = 0x7C00;
   .text : { *(.text) }
   .data : { *(.data) }
   .bss  : { *(.bss)  }
 }