#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main() {
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Before Bubble Sort:\narr = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);

    cout << "\nAfter Bubble Sort:\narr = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
