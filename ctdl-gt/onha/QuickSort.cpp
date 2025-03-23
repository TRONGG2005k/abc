#include <iostream>
using namespace std;
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void quickSort(int arr[], int low, int high) {
    if (low >= high) return;  // Điều kiện dừng đệ quy
    int count = 0;
    int pivot = arr[low + (high - low) / 2];  // Chọn pivot là phần tử giữa
    int i = low - 1, j = high + 1; 
    // cout << "lan lap " << ++count<< endl;
    cout <<"chot =" << pivot <<endl;
    while (true) {
        do {
            i++;
            if (arr[i] < pivot) {
                cout << "i = " << i << ", " << arr[i] << " be hon " << pivot << " di tiep" << endl;
            } else {
                cout << "i = " << i << ", " << arr[i] << " lon hon hoac bang " << pivot << " dung" << endl;
            }
        } while (arr[i] < pivot);  // Tìm phần tử >= pivot
        do {
            j--;
            if (arr[j] > pivot) {
                cout << "j = " << j << ", " << arr[j] << " lon hon " << pivot << " di tiep" << endl;
            } else {
                cout << "j = " << j << ", " << arr[j] << " nho hon hoac bang " << pivot << " dung" << endl;
            }
           
        } while (arr[j] > pivot);  // Tìm phần tử <= pivot
    
        if (i >= j){
            cout<<"i va j gap nhau" << "\n";
            // cout << " Chia mang thanh 2 phan: [" << low << "..." << j << "] va [" << (j + 1) << "..." << high << "]\n\n";
            break;
        }   // Khi hai con trỏ gặp nhau, dừng
        cout << "Hoan doi " << arr[i] << " va " << arr[j] << endl;
        swap(arr[i], arr[j]);  // Hoán đổi
        printArray(arr, high+1);
        cout << endl;
    }
    

    quickSort(arr, low, j);  // Đệ quy cho phần trái
    quickSort(arr, j + 1, high);  // Đệ quy cho phần phải
}

// Hàm in mảng


// Hàm chính
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    printArray(arr, n);
    cout << "\n\n";
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
