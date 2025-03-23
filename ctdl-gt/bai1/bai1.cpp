#include<iostream>
using namespace std;

// Hàm tìm ước chung lớn nhất (GCD) sử dụng thuật toán Euclidean
int findGCD(int a, int b) {
    int i = 0;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        cout << "Lan lap thu " << ++i << ": a = " << a << ", b = " << b << endl;
    }
    return a;
}

// Hàm tìm bội chung nhỏ nhất (LCM)
int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

int main() {
    int num1, num2;
    
    cout << "Nhap so thu nhat: ";
    cin >> num1;
    cout << "Nhap so thu hai: ";
    cin >> num2;
    
    int gcd = findGCD(num1, num2);
    int lcm = findLCM(num1, num2);
    
    cout << "Uoc chung lon nhat (GCD) cua " << num1 << " va " << num2 << " la: " << gcd << endl;
    cout << "Boi chung nho nhat (LCM) cua " << num1 << " va " << num2 << " la: " << lcm << endl;
    
    return 0;
}