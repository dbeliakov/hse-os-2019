#include <dlfcn.h>
#include <stdio.h>

int main()
{
    void* handle = dlopen("lib/liblib.so", RTLD_LAZY);
    if (handle == NULL) {
        printf("Cannot open shared library: %s\n", dlerror());
        return 1;
    }

    void* sym = dlsym(handle, "printHello");
    ((void(*)())sym)();

    dlclose(handle);
    return 0;
}
