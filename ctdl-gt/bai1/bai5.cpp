#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
int main(int argc, char** argv) {
    float A, B;
    char C,ch;
    int i = 0;
    do {
    printf("Nhap bieu thuc:");
    scanf("%f%c%f", &A, &C, &B);
    switch (C) {
        case '+':
        printf("%3.2f %c %3.2f = %3.2f\n", A, C, B, A+B);
        break;
        case '-':
        printf("%3.2f %c %3.2f = %3.2f\n", A, C, B, A-B);
        break;
        case '*':
        printf("%3.2f %c %3.2f = %3.2f\n", A, C, B, A*B);
        break;
        case '/':
        printf("%3.2f %c %3.2f = %3.2f\n", A, C, B, A/B);
        break;
        default:
        printf("Nhap sai\n");
        break;
    }
    printf("Enter tiep tuc ESC thoat\n");
    ch = getch();

    cout << ++i << endl;
    

    } while (ch != 27);
    return 0;
}