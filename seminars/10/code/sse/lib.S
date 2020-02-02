        .text

        .global sqrt
sqrt:
        pushl   %ebp
        movl    %esp, %ebp
        movsd   8(%ebp), %xmm0
        sqrtsd  %xmm0, %xmm0
        subl    $8, %esp
        movsd   %xmm0, (%esp)
        fldl    (%esp)
        addl    $8, %esp
        popl    %ebp
        ret

        .global mul
mul:
        pushl   %ebp
        movl    %esp, %ebp
        movsd   8(%ebp), %xmm0
        movsd   16(%ebp), %xmm1
        mulsd    %xmm1, %xmm0
        subl    $8, %esp
        movsd   %xmm0, (%esp)
        fldl    (%esp)
        addl    $8, %esp
        popl    %ebp
        ret
