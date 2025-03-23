#include <iostream>
using namespace std;

// Hàm đệ quy tính số Fibonacci thứ n
// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hàm không đệ quy tính số Fibonacci thứ n
// Function to calculate the nth Fibonacci number using iteration
int fibonacci1(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter the position to find the Fibonacci number: ";
    cin >> n;
    
    cout << "Fibonacci number at position " << n << " (using recursion): " << fibonacci(n) << endl;
    cout << "Fibonacci number at position " << n << " (using iteration): " << fibonacci1(n) << endl;
    
    return 0;
}