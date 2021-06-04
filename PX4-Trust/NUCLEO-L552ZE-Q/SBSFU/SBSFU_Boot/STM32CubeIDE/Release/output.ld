;
MEMORY
{
  FLASH (rx) : ORIGIN = ((((0x0C000000)) + (((0x0000)+(0x1000))))), LENGTH = (((0x800))+((0xb000)))
  FLASH_NOHDP (rx) : ORIGIN = ((((0x0C000000)) + (((((0x0000)+(0x1000))+(0x800))+(0xb000))))), LENGTH = ((0x800))
  RAM (rwx) : ORIGIN = ((((0x30000000)) + ((0x30000)))), LENGTH = ((0x30040000) - ((((0x30000000)) + ((0x30000)))))
}
__heap_size__ = 0x0000000;
__msp_stack_size__ = 0x0001400;
GROUP(libgcc.a libc.a libm.a libnosys.a)
ENTRY(Reset_Handler)
SECTIONS
{
 .provision :
 {
  KEEP(*(.provision)) ;
 } > FLASH
 .BL2_NoHdp_Code :
    {
        *mpu_armv8m_drv.o (.text* .rodata*)
        KEEP(*(.BL2_NoHdp_Code))
    } > FLASH_NOHDP
 .text (((((0x0C000000)) + ((((0x0000)+(0x1000))+(0x800)))))):
    {
        KEEP(*(.vectors))
        __Vectors_End = .;
        __Vectors_Size = __Vectors_End - __Vectors;
        __end__ = .;
        *(.text*)
        KEEP(*(.init))
        KEEP(*(.fini))
        *crtbegin.o(.ctors)
        *crtbegin?.o(.ctors)
        *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
        *(SORT(.ctors.*))
        *(.ctors)
         *crtbegin.o(.dtors)
         *crtbegin?.o(.dtors)
         *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
         *(SORT(.dtors.*))
         *(.dtors)
        *(.rodata*)
        KEEP(*(.eh_frame*))
    } > FLASH
    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH
    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > FLASH
    __exidx_end = .;
    .copy.table :
    {
        . = ALIGN(4);
        __copy_table_start__ = .;
        LONG (__etext)
        LONG (__data_start__)
        LONG (__data_end__ - __data_start__)
        LONG (DEFINED(__etext2) ? __etext2 : 0)
        LONG (DEFINED(__data2_start__) ? __data2_start__ : 0)
        LONG (DEFINED(__data2_start__) ? __data2_end__ - __data2_start__ : 0)
        __copy_table_end__ = .;
    } > FLASH
    .zero.table :
    {
        . = ALIGN(4);
        __zero_table_start__ = .;
        LONG (__bss_start__)
        LONG (__bss_end__ - __bss_start__)
        LONG (DEFINED(__bss2_start__) ? __bss2_start__ : 0)
        LONG (DEFINED(__bss2_start__) ? __bss2_end__ - __bss2_start__ : 0)
        __zero_table_end__ = .;
    } > FLASH
    __etext = .;
    .data : AT (__etext)
    {
        __data_start__ = .;
        *(vtable)
        *(.data*)
        . = ALIGN(4);
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP(*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);
        . = ALIGN(4);
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE_HIDDEN (__init_array_end = .);
        . = ALIGN(4);
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        PROVIDE_HIDDEN (__fini_array_end = .);
        KEEP(*(.jcr*))
        . = ALIGN(4);
        __data_end__ = .;
    } > RAM
 Image$$ER_CODE$$Base = __Vectors ;
    Image$$ER_CODE$$Limit = __etext + + SIZEOF(.data);
    .bss :
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM
    bss_size = __bss_end__ - __bss_start__;
    .msp_stack :
    {
        . = ALIGN(8);
        KEEP(*(.psp_stack*))
        . += __msp_stack_size__;
    } > RAM
    Image$$ARM_LIB_STACK$$ZI$$Limit = ADDR(.msp_stack) + SIZEOF(.msp_stack);
    Image$$ARM_LIB_STACK$$ZI$$Base = ADDR(.msp_stack) ;
    .heap :
    {
        . = ALIGN(8);
        __end__ = .;
        PROVIDE(end = .);
        __HeapBase = .;
        . += __heap_size__;
        __HeapLimit = .;
        __heap_limit = .;
    } > RAM
    PROVIDE(__stack = Image$$ARM_LIB_STACK$$ZI$$Limit);
}
