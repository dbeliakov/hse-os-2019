        .text

        .global sqrt
sqrt:
        pushl   %ebp
        movl    %esp, %ebp
        fldl    8(%ebp)
        fsqrt
        popl    %ebp
        ret

        .global mul
mul:
        pushl   %ebp
        movl    %esp, %ebp
        fldt    8(%ebp)
        fldt    20(%ebp)
        fmul    %st(1), %st
        popl    %ebp
        ret
