#include <iostream>
using namespace std;

// Hàm tìm kiếm phần tử x trong mảng bằng đệ quy
int findElementRecursive(int arr[], int size, int x, int index) {
    if (index >= size) {  // Điều kiện dừng: duyệt hết mảng
        return -1;
    }
    if (arr[index] == x) {  // Nếu tìm thấy phần tử
        return index;
    }
    return findElementRecursive(arr, size, x, index + 1);  // Gọi đệ quy cho phần tử tiếp theo
}

// Hàm tìm kiếm tuyến tính (không đệ quy)
int linearSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;  // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1;  // Không tìm thấy
}

int main(int argc, char** argv) {
    int arr[] = {3, 8, 4, 7, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x;  // Nhập phần tử cần tìm
                                
    cout << "Phan tu can tim: ";
    cin >> x;
    
    // Tìm kiếm đệ quy
    int result = findElementRecursive(arr, size, x, 0);
    cout << "Tim kiem de quy:\n";
    if (result != -1) {
        cout << "Phan tu " << x << " duoc tim thay tai chi so " << result << endl;
    } else {
        cout << "Phan tu " << x << " khong ton tai trong mang" << endl;
    }
    
    // Tìm kiếm không đệ quy
    int result2 = linearSearch(arr, size, x);
    cout << "Tim kiem khong de quy:\n";
    if (result2 != -1) {
        cout << "Phan tu " << x << " duoc tim thay tai chi so " << result2 << endl;
    } else {
        cout << "Phan tu " << x << " khong ton tai trong mang" << endl;
    }
    
    return 0;
}