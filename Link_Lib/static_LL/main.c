#include <stdio.h>
#include "my_compute.h"

int main(void) {
    printf("3 + 4 = %d\n", my_sum(3, 4));
    printf("3 - 4 = %d\n", my_sub(3, 4));
    return 0;
}