#include <iostream>
#include <cmath> // Thư viện toán học để dùng sqrt()
using namespace std;
bool isPrime(int n) {
    int j = 0;
    if (n < 2)
    cout << "O(1)" << endl;
    return false;   // Số nhỏ hơn 2 không phải số nguyên tố
    if (n == 2 || n == 3)
    cout << "O(1)" << endl;
    return true; // 2 và 3 là số nguyên tố
    if (n % 2 == 0)
    cout << "O(1)" << endl;
    return false;  // Số chẵn (trừ 2) không phải số nguyên tố
    // Kiểm tra từ 3 đến sqrt(n), bỏ qua số chẵn
    for (int i = 3; i <= sqrt(n); i += 2) {
        cout << "Lan lap thu " << ++j << ": i = " << i << endl;
    if (n % i == 0)
    return false; // Nếu chia hết thì không phải số nguyên tố
    }    
    return true;
}
int main() {
    int n;    cout << "Nhap mot so nguyen duong: ";
    cin >> n;
    if (isPrime(n))
    cout << n << " la so nguyen to." << endl;
    else
    cout << n << " khong phai so nguyen to." << endl;
    return 0;
}
