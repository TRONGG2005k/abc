#include <iostream>
using namespace std;

// Hàm chèn phần tử x vào vị trí pos
void insertElement(int arr[], int &n, int x, int pos) {
    if (pos < 0 || pos > n) {
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    
    // Dịch các phần tử sang phải
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Chèn phần tử mới
    arr[pos] = x;
    n++; // Tăng kích thước mảng
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    int arr[100] = {1, 2, 3, 5, 6}; // Mảng có sẵn
    int n = 5;    // Kích thước mảng
    int x = 4;    // Giá trị cần chèn
    int pos = 3;  // Vị trí chèn
    
    cout << "Mang truoc khi chen: ";
    printArray(arr, n);
    
    insertElement(arr, n, x, pos);
    
    cout << "Mang sau khi chen: ";
    printArray(arr, n);
    
    return 0;
}