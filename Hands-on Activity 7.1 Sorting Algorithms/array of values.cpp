// Array of Values for Sort Algorithm Testing
#include <iostream>
#include <cstdlib>
#include <ctime>
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
  return 0;
}
