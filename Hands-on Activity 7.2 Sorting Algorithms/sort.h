#include <iostream>
#include <cstdlib>
using namespace std;
 
void shellSort(int arr[], int size) 
{
        
        for (int interval = size / 2; interval > 0; interval /= 2) 
        {
            for (int i = interval; i < size; i++) {
                int temp = arr[i];
                int j;

                for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                    arr[j] = arr[j - interval];
                }
                arr[j] = temp;
            }
        }
    }


void merge(int arr[], int left, int middle, int right) 
{
    int n1 = middle - left + 1; 
    int n2 = right - middle;     

    int* L = new int[n1];
    int* R = new int[n2];

    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    
    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


void mergeSort(int arr[], int left, int right) 
{
    if (left < right) {

        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
