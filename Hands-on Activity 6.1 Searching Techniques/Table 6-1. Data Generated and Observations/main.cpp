#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int max_size = 50;

int main() 
{
    // generate random values
    int dataset[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) 
	{
        dataset[i] = rand();
    }

    // show your datasets content
    for (int i = 0; i < max_size; i++) 
	{
        cout << dataset[i] << " ";
    }

    return 0;
}

