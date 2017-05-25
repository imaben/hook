#include <stdio.h>
#include <dlfcn.h>

typedef char *(*strcpyfn)(char *, const char *);

char *strcpy(char *dst, char *src)
{
    static void *handle = NULL;
    static strcpyfn fn = NULL;

    if (!handle) {
        handle = dlopen("libc.so.6", RTLD_LAZY);
        fn = (strcpyfn)dlsym(handle, "strcpy");
    }
    char *r = fn(dst, src);
    strcat(dst, "HOOK");
    return r;
}
