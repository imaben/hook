#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char src[] = "Hello world";
    char dst[32] = {0};

    strcpy(dst, src);

    printf("dst:%s\n", dst);
    return 0;
}
