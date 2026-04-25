#include <stdio.h>
#include <math.h>


int main() {
    int a = 10;
    int b = 3;

    printf("%d\n", a + b);             // 13 (divisão)
    printf("%d\n", a - b);             // 7 (subtração)
    printf("%d\n", a * b);             // 30 (multiplicação)
    printf("%d\n", a / b);             // 3 (divisão inteira)
    printf("%d\n", a % b);             // 1 (resto)
    printf("%.2f\n", (double)a / b);   // 3.33 (disivão fracionária)
    printf("%d\n", (int)pow(a,b));     // a**b = 10**3 = 1000 (potenciação)
} 