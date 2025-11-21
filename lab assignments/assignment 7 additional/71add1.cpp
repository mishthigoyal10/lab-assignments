#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int count[maxVal + 1];
    for(int i = 0; i <= maxVal; i++) {
        count[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for(int i = 0; i <= maxVal; i++) {
        while(count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
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

    countingSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
