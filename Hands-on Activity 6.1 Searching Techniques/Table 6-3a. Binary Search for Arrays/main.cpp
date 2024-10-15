#include <iostream>
#include "searching.h"
using namespace std;

int main() 
{
    int dataset[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(dataset) / sizeof(dataset[0]);
    
    int searchItem;
    cout << "Enter a number to search: ";
    cin >> searchItem;
    
    binarySearch(dataset, size, searchItem);
    
    return 0;
}

