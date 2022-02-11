//
// Created by Vic on 2/11/22.
//
#include <stdio.h>

int main() {
    int a = 10;
    int *b = &a;
    int c = *b;

    printf("The address of %d is %p. The value is %d.", a, b, c);
    return 0;
}
