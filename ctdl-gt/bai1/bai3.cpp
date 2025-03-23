#include <iostream>
 #include <stdio.h>
 #include <conio.h>
 /* run this program using the console pauser or add your own getch, system("pause") or input loop */
 unsigned long giaithua(int n){
 unsigned long ketqua = 1;
 using namespace std;   
 int i;
int j = 0;
 for (i=2; i<=n; i++)
 ketqua *= i;
cout << "Lan lap thu " << ++j << ": i = " << i << ", ketqua = " << ketqua << endl;
 return ketqua;
 }
 int main(int argc, char** argv) {
 int n;
 printf("Nhap vao gia tri N : ");
 scanf("%d", &n);
 printf("%d! = %lu", n, giaithua(n));
 getch();
 return 0;
 }