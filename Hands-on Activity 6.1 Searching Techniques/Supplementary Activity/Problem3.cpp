#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int up = size - 1;

    while (low <= up) {
        int mid = low + (up - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } 
        else if (arr[mid] < key) {
            low = mid + 1;
        } 
        else {
            up = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = binarySearch(arr, size, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}

