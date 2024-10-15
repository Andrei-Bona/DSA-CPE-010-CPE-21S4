#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
using namespace std;

bool binarySearch(int arr[], int size, int no) 
{
    int low = 0;
    int up = size - 1;

    while (low <= up) {
        int mid = low + (up - low) / 2; 
        if (arr[mid] == no) 
		{
            cout << "Search element is found!" << endl;
            return true;  
        } else if (no < arr[mid]) 
		{
            up = mid - 1;  
        } else {
            low = mid + 1;  
        }
    }

    cout << "Search element is not found." << endl;
    return false;  
}

#endif 

