        .section .rodata
format:
        .string "%d\n"

        .text
        .global main

main:
        pushl   %ebp
        movl    %esp, %ebp

        pushl   $10
        pushl   $25
        call    apb
        addl    $8, %esp

        pushl   %eax
        pushl   $format
        call    printf
        addl    $8, %esp

        popl    %ebp
        movl    $0, %eax
        ret

// int apb(int a, int b);
apb:
        pushl   %ebp
        movl    %esp, %ebp
        movl    8(%ebp), %eax
        addl    12(%ebp), %eax
        popl    %ebp
        ret