        .section .rodata
format:
        .string "%d\n"

        .bss
arr:
        .space  40

        .text
        .global main
main:
        pushl   %ebp
        movl    %esp, %ebp
        call    fill_arr
        call    print_arr
        popl    %ebp
        movl    $0, %eax
        ret

// void fill_arr();
fill_arr:
        pushl   %ebp
        movl    %esp, %ebp
        movl    $0, %ecx
fill_loop:
        movl    %ecx, arr(,%ecx,4)
        incl    %ecx
        cmpl    $10, %ecx
        jl      fill_loop

        popl    %ebp
        ret

// void print_arr();
print_arr:
        pushl   %ebp
        movl    %esp, %ebp
        movl    $0, %ebx
print_loop:
        pushl   arr(,%ebx,4)
        pushl   $format
        call    printf
        addl    $8, %esp
        incl    %ebx
        cmpl    $10, %ebx
        jl      print_loop

        popl    %ebp
        ret