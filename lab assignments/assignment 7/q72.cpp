#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while(left < right) {
        int minIndex = left;
        int maxIndex = left;

        // find min and max in current range
        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if(arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // swap minimum with left side
        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        // if maxIndex was at left, after swapping it moved to minIndex
        if(maxIndex == left) {
            maxIndex = minIndex;
        }

        // swap maximum with right side
        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter how many numbers you want to sort: ";
    cin >> n;

    int arr[n];
    cout << "Enter the numbers:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
