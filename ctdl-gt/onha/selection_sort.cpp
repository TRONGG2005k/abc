#include<iostream>
using namespace std;

int selection_sort(int arr[], int n) {
    int min;
    int k;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for (int h = i; h < n; h++){   
            if(arr[h] < arr[min]) {
                min = h;
            }
            cout<< string(h * 2, ' ')<<"min"<<endl;
            cout<< string(h * 2, ' ') << arr[min] << endl;
            for( k = 0; k < n; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
            
        }
        
        if(min != i) {
            cout << "doi cho vi chi " << i << " va " << min << endl;
            swap(arr[i], arr[min]);
        }
        
    }
    return min;
}

int main() {
    int arr[] = {5, 3, 2, 4, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    selection_sort(arr, n);
    return 0;
}