#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.h"
using namespace std;

int main()
{
    const int max_size = 100;
    
    // generate random values
    int arr[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) 
	{
        arr[i] = rand() % 100;
    }

    // show your array content
    cout << "Unsorted array: " <<endl;
    for (int i = 0; i < max_size; i++) 
	{
        cout << arr[i] << " ";
    }

    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    cout <<endl;
    cout <<endl;
    
//    bubbleSort(arr, arrSize);
//    selectionSort(arr, arrSize);
    insertionSort(arr, arrSize);
    cout << "Sorted array: " << endl;
    for (size_t i = 0; i < arrSize; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
