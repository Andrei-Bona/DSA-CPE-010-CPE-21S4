#include <iostream>
#include <cstdlib> 
#include <time.h>  
#include "searching.h"
#include "nodes.h"
using namespace std;

const int max_size = 50;

int main() 
{
    int dataset[max_size];
    

    srand(time(0));

 
    for (int i = 0; i < max_size; i++) 
	{
        dataset[i] = rand();
    }

/*
    // Display dataset content
    cout << "Generated dataset: ";
    for (int i = 0; i < max_size; i++) 
	{
        cout << dataset[i] << " ";
    }
  	cout <<endl;
*/

    int search_item;
    cout << "Enter an item to search: ";
    cin >> search_item;
    
    bool result = linearSearch(dataset, max_size, search_item);
    if (result) 
	{
        cout << "Searching is successful" << endl;
    } else 
	{
        cout << "Searching is unsuccessful" << endl;
    }

    return 0;
}

