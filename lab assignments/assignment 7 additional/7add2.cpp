#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

void countingSortExp(int arr[], int n, int exp) {
    int output[n];
    int count[10];

    for(int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxNum = getMax(arr, n);
    for(int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSortExp(arr, n, exp);
    }
}

int main() {
    int n;
    cout << "Enter how many numbers: ";
    cin >> n;

    int arr[n];
    cout << "Enter the numbers:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
