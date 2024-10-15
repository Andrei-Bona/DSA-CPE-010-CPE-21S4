#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include "nodes.h"

using namespace std;

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last) 
{
    if (start == NULL) return NULL;

    Node<T>* slow = start;
    Node<T>* fast = start->next;

    while (fast != last) 
	{
        fast = fast->next;
        if (fast != last) 
		{
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;  
}


template <typename T>
bool binarySearch(Node<T>* head, T key) 
{
    Node<T>* start = head;
    Node<T>* last = NULL;

    while (start != last) 
	{
        Node<T>* mid = getMiddle(start, last);  

        if (mid->data == key) 
		{
            cout << "Search element is found: " << mid->data << endl;
            return true;  
        } else if (mid->data > key) 
		{
            last = mid;  
        } else 
		{
            start = mid->next;  
        }
    }

    cout << "Search element is not found." << endl;
    return false;  
}

#endif 

