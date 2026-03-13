#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 10;
    int *array = malloc(num*sizeof(int));

    for (int i = 0; i < 10; i++) {
        int par = 2*i;
        array[i] = par;
    }

    for (int j = 0; j < 10; j++) {
        printf("%d\n", array[j]);
    }

    printf("\n");
    printf("%p\n", array); // 00D32F10
    printf("%d",*(array+5)); // >> 
    return 0;
}