#include<iostream>
using namespace std;

void insertionSort (int a[], int n) {
    for(int i = 1; i < n; i++){
        int key = a[i];
        int pos = i - 1;
        cout << "buoc " << i << ": xet phan tu  " << key << endl;
        int count = 0;
        while (pos >= 0 && key < a[pos])
        { 
            cout << "   dich phan tu " << a[pos] << " sang phai "<< endl;
            a[pos + 1] = a[pos];
            --pos; 
        }
        a[pos + 1] = key;
        for(int j = 0; j < i+1; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[8] = {4, 5, 1, 3, 9, 0, 1, 4};

    cout << "\n\n";

    insertionSort(a, 8);

    cout << "\nMang sau khi sap xep: ";
    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
}