#include <stdio.h>
#define MAX 100
void convert(int n, int base) {
    char stack[MAX];
    int top = -1;
    char digits[] = "0123456789ABCDEF";
    while (n > 0)
        stack[++top] = digits[n % base], n /= base;
    while (top >= 0)
        printf("%c", stack[top--]);
    printf("\n");
}
int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Binary: "); convert(n, 2);
    printf("Octal: "); convert(n, 8);
    printf("Hexadecimal: "); convert(n, 16);
    return 0;
}
