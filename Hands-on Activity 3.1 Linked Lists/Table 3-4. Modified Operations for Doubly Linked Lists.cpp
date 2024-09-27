#include <iostream>
using namespace std;

class Node 
{
    public:
        float data;    
        Node *next;   
        Node *prev;    
};


void traverseForward(Node *head) 
{
    Node *current = head;
    while (current != nullptr) 
    {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}


void traverseBackward(Node *tail) 
{
    Node *current = tail;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->prev;
    }
    cout << "nullptr" << endl;
}


void insertAtHead(Node *&head, float newData) 
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) 
    {
        head->prev = newNode;
    }
    head = newNode;
}


void insertAtEnd(Node *&head, float newData) 
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node *last = head;
    while (last->next != nullptr) 
    {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last; 
}


void insertAfter(Node *prevNode, float newData) 
{
    if (prevNode == nullptr) 
    {
        cout << "Previous node cannot be null." << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != nullptr) 
    {
        prevNode->next->prev = newNode; 
    }
    prevNode->next = newNode; 
}


void deleteNode(Node *&head, float key) 
{
    Node *temp = head;


    if (temp != nullptr && temp->data == key) 
    {
        head = temp->next; 
        if (head != nullptr) 
        {
            head->prev = nullptr; 
        }
        delete temp; 
        return;
    }

   
    while (temp != nullptr && temp->data != key) 
    {
        temp = temp->next;
    }

    
    if (temp == nullptr) return;

  
    if (temp->next != nullptr) 
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) 
    {
        temp->prev->next = temp->next;
    }
    delete temp;
}


int main()
{
    Node *head = nullptr;

   
    insertAtEnd(head,  4 );
    insertAtEnd(head,  5 );
    insertAtEnd(head,  6 );
    insertAtEnd(head,  7 );

    cout << "Initial list: ";
    traverseForward(head);  

    insertAtHead(head,  3 );
    cout << "After inserting '3' at head: ";
    traverseForward(head);  


    insertAtEnd(head,  8 );
    cout << "After inserting '8' at end: ";
    traverseForward(head);  

  
    insertAfter(head->next->next,  5.5 ); 
    cout << "After inserting '5.5' after '5': ";
    traverseForward(head); 

   
    deleteNode(head,  6 );
    cout << "After deleting '6': ";
    traverseForward(head);   

    return 0;
}



