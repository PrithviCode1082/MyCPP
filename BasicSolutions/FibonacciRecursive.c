#include <stdio.h>

void printSeries(int i, int num, int op1, int op2) {
    if (i < num) {
        printf("%d\n", (op2 + op1));
        printSeries(i + 1, num, op2, op2 + op1);
    }
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("0\n1\n");
    printSeries(2, num, 0, 1);
    return 0;
}
