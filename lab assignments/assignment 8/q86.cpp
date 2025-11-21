#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() {
        size = 0;
    }

    void swapValues(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void insert(int value) {
        if(size == 100) {
            cout << "Priority Queue is full!" << endl;
            return;
        }

        arr[size] = value;
        int i = size;
        size++;

        while(i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swapValues(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }

        cout << "Inserted " << value << endl;
    }

    int getMax() {
        if(size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return arr[0];
    }

    int extractMax() {
        if(size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }

        int maxValue = arr[0];
        arr[0] = arr[size - 1];
        size--;

        int i = 0;

        while(true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if(left < size && arr[left] > arr[largest])
                largest = left;

            if(right < size && arr[right] > arr[largest])
                largest = right;

            if(largest != i) {
                swapValues(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }

        return maxValue;
    }

    void display() {
        if(size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue Elements: ";
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while(true) {
        cout << "\n--- PRIORITY QUEUE USING HEAP ---" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Get Maximum" << endl;
        cout << "3. Extract Maximum" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            pq.insert(value);
            break;

        case 2:
            value = pq.getMax();
            if(value != -1)
                cout << "Maximum element: " << value << endl;
            break;

        case 3:
            value = pq.extractMax();
            if(value != -1)
                cout << "Extracted maximum: " << value << endl;
            break;

        case 4:
            pq.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
