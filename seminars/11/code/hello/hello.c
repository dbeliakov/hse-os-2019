__asm__(
    ".text\n\t"
    ".global _start\n\t"
    "_start:\n\t"

    "popl   %eax\n\t"
    "leal   (%esp,%eax,4), %ecx\n\t"
    "addl   $4, %ecx\n\t"
    "movl   %esp, %ebx\n\t"

    "pushl  %ecx\n\t"
    "pushl  %ebx\n\t"
    "pushl  %eax\n\t"
    "call   main\n\t"

    "pushl  %eax\n\t"
    "call   exit\n\t"
);

#define NULL 0

void exit(int code)
{
    __asm__ volatile(
        "int     $0x80\n\t"
        ::"b"(code),"a"(1)
    );
    for(;;) {}
}

int strlen(const char* const str)
{
    const char* it = str;
    while (*it) ++it;
    return it - str;
}

int write_stdout(const char* const str)
{
    int len = strlen(str);
    int res;
    __asm__ volatile(
        "int    $0x80\n\t"
        :"=a"(res)
        :"a"(4),"b"(1),"c"(str),"d"(len)
    );
    return res;
}

int main(int argc, char** argv, char** env)
{
    for (int i = 0; i < argc; ++i) {
        write_stdout(argv[i]);
        write_stdout("\n");
    }
    int i = 0;
    while (env[i] != NULL) {
        write_stdout(env[i++]);
        write_stdout("\n");
    }
    return argc;
}
