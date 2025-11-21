#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, a[100], i;
    cin >> n;

    for(i = 0; i < n; i++) cin >> a[i];

    bubbleSort(a, n);

    for(i = 0; i < n; i++) cout << a[i] << " ";
}
