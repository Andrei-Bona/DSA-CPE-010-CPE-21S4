#include <iostream>

using namespace std;

int recursiveBinarySearch(int arr[], int low, int up, int key) {
    if (low > up) {
        return -1;
    }

    int mid = low + (up - low) / 2;

    if (arr[mid] == key) {
        return mid;
    } 
    else if (arr[mid] < key) {
        return recursiveBinarySearch(arr, mid + 1, up, key);
    } 
    else {
        return recursiveBinarySearch(arr, low, mid - 1, key);
    }
}

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = recursiveBinarySearch(arr, 0, size - 1, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}

