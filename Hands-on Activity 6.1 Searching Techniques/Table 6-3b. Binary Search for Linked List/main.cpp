#include <iostream>
#include "nodes.h"
#include "searching.h"

using namespace std;

int main() 
{
    char choice = 'y'; 
    int count = 0; 
    int newData;
    Node<int>* head = NULL;
    Node<int>* temp;

    while (choice == 'y') 
	{
        cout << "Enter data: ";
        cin >> newData;

        Node<int>* node = new_node(newData);
        if (head == NULL) 
		{
            head = node;  
            cout << "Successfully added " << head->data << " to the list.\n";
        } else 
		{
            temp = head;
            while (temp->next != NULL) 
			{ 
                temp = temp->next;
            }
            temp->next = node;  
            cout << "Successfully added " << node->data << " to the list.\n";
        }

        count++;
        cout << "Continue? (y/n): ";
        cin >> choice;
    }

   
    Node<int>* currNode = head;
    cout << "Linked list contents: ";
    while (currNode != NULL) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;

   
    int searchKey;
    cout << "Enter a number to search: ";
    cin >> searchKey;
    
    binarySearch(head, searchKey);

    return 0;
}

