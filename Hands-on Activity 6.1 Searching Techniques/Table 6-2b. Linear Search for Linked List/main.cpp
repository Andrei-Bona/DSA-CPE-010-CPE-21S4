#include <iostream>
#include "nodes.h"
#include "searching.h"
using namespace std;

int main() 
{

    Node<char> *name1 = new_node('B');
    Node<char> *name2 = new_node('O');
    Node<char> *name3 = new_node('N');
    Node<char> *name4 = new_node('A');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = NULL;
    

    char searchChar;
    cout << "Enter a character to search in the linked list: ";
    cin >> searchChar;

    bool found = linearLS(name1, searchChar);
    if (found) 
	{
        cout << "Character '" << searchChar << "' found in the linked list." << endl;
    } else {
        cout << "Character '" << searchChar << "' not found in the linked list." << endl;
    }

    return 0;
}

