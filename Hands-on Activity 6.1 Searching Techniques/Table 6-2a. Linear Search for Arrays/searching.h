#define SEARCHING_H

bool linearSearch(int data[], int size, int item) 
{
    for (int i = 0; i < size; i++) 
	{
        if (data[i] == item) 
		{
            return true;
        }
    }
    return false;
}



