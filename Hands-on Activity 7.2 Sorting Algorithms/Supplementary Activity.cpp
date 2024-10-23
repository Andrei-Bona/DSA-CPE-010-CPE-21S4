#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void bubbleSort(int arr[], int low, int high) {
    for (int i = low; i < high; i++) {
        for (int j = low; j < high - (i - low); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void hybridQuickBubbleSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        bubbleSort(arr, low, pivotIndex - 1);
        bubbleSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    const int max_size = 100;
    int arr[max_size];

    srand(time(0));
    for (int i = 0; i < max_size; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Unsorted array: ";
    for (int i = 0; i < max_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    hybridQuickBubbleSort(arr, 0, max_size - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < max_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
