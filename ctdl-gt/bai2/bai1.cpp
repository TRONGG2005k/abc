#include<iostream>

using namespace std;

long long gt(long long n) {
    if(n == 0) return 1;
    return n * gt(n-1);
    
}
long long gt1(long long n) { 
    long long s = 1;
    for(int i = 1; i <= n; i++) {
        s *= i;
    }
    return s;
}
int main() {
    long long n;
    cin >> n;
    cout << gt(n) << endl;
    cout << gt1(n) << endl;
}