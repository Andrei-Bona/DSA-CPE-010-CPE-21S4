#define SEARCHING_H
#include "nodes.h"

template <typename T>
bool linearLS(Node<T> *head, T dataFind) 
{
    Node<T> *current = head;
    while (current != NULL) 
	{
        if (current->data == dataFind) 
		{
            return true; 
        }
        current = current->next;  
    }
    return false;  
}



