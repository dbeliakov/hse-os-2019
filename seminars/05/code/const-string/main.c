void foo(const char* str)
{
    *((char*) str) = 'h';
}

int main()
{
    char str[] = "Hello";
    foo(str);

    // const char cstr[] = "Hello";
    // Error
    // foo(cstr);

    // char* pstr = "world";
    // == static const char str_constant[] = "world"; char* pstr = str_constant;
    // Error
    // foo(pstr);
}
