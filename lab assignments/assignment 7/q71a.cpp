#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    int i, j, minIndex, temp;
    for(i = 0; i < n-1; i++) {
        minIndex = i;
        for(j = i+1; j < n; j++) {
            if(a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main() {
    int n, a[100], i;
    cin >> n;

    for(i = 0; i < n; i++) cin >> a[i];

    selectionSort(a, n);

    for(i = 0; i < n; i++) cout << a[i] << " ";
}
