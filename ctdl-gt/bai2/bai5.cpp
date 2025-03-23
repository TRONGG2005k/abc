#include <iostream>
using namespace std;

// Hàm xóa phần tử tại vị trí pos
void deleteElement(int arr[], int &n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Vi tri xoa khong hop le!\n";
        return;
    }
    
    // Dịch các phần tử sang trái
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }    
    n--; // Giảm kích thước mảng
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    int arr[100] = {1, 2, 3, 4, 5}; // Mảng có sẵn
    int n = 5;
    int pos = 2; // Xóa phần tử ở vị trí 2 (số 3)
    
    cout << "Mang truoc khi xoa: ";
    printArray(arr, n);
    
    deleteElement(arr, n, pos);
    
    cout << "Mang sau khi xoa: ";
    printArray(arr, n);
    
    return 0;
}