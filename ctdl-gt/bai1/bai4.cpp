#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
int main(int argc, char** argv) {
int A, B;
printf(" A = ");
scanf("%d", &A);
printf(" B = ");
if (A>B)
scanf("%d", &B);
printf("%d > %d\n", A, B);
if (A<B)
printf("%d < %d\n", A, B);
if (A==B)
printf("%d = %d\n", A, B);
getch();

cout << "Hello world! O(1)" << endl;
return 0;
}