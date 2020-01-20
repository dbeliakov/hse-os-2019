        .section .rodata
hello_str:
        .string "Hello, world!"
hello_format:
        .string "%s\n";

        .text
        .global main
main:
        pushl   %ebp
        movl    %esp, %ebp
        call    print_hello_world
        popl    %ebp
        movl    $0, %eax
        ret

print_hello_world:
        pushl   %ebp
        movl    %esp, %ebp
        push    $hello_str
        push    $hello_format
        call    printf
        addl    $8, %esp
        popl    %ebp
        ret