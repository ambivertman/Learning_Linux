#include<header.h>

int main(void) {
    int num = 0x61626364;
    char *p = (char *)&num;
    for (int i = 0;i < 4;i++) {
        printf("%c ", p[i]);
    }

    return 0;
}