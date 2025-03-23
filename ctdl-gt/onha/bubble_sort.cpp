#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    cout << "Bat dau thuat toan Bubble Sort:\n";

    for (int i = 0; i < n; i++) {
        cout << "Lan lap " << i + 1 << ": " << endl;
        for (int j = 0; j < n - 1 - i; j++) {
            cout << "  So sanh a[" << j << "] = " << a[j] << " va a[" << j + 1 << "] = " << a[j + 1];

            if (a[j] > a[j + 1]) {
                cout << " => Hoan doi!\n";
                swap(a[j], a[j + 1]);
                // swapped = true;
            } else {
                cout << " => Khong hoan doi\n";
            }
        }
        cout << "  Mang sau lan lap " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << "\n";
        cout << "-----------------------------\n";
    }
}

int main() {
    int a[8] = {4, 5, 1, 3, 9, 0, 1, 4};
    
    cout << "Mang ban dau: ";
    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    bubbleSort(a, 8);

    cout << "\nMang sau khi sap xep: ";
    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
}
