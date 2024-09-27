#include <iostream>
using namespace std;

class Node 
{
    public:
        char data;
        Node *next;
};


void traversal(Node *n) 
{
    while (n != nullptr) 
    {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << "nullptr" << endl;
}


void insertAtHead(Node *&head, char newData) 
{
    Node *newNode = new Node();
    newNode->data = newData;      
    newNode->next = head;      
    head = newNode;              
}


void insertAtEnd(Node *&head, char newData) 
{
    Node *newNode = new Node();  
    newNode->data = newData;     
    newNode->next = nullptr;      
    if (head == nullptr) 
    {
        head = newNode;           
        return;
    }

    Node *last = head;
    while (last->next != nullptr) 
    {
        last = last->next;        
    }
    last->next = newNode;        
}



void insertAfter(Node *previousNode, char newData) 
{
    if (previousNode == nullptr) 
    {
        cout << "Previous node cannot be null." << endl;
        return;
    }

    Node *newNode = new Node();  
    newNode->data = newData;      
    newNode->next = previousNode->next;  
    previousNode->next = newNode; 
}


void deleteNode(Node *&head, char key) 
{
    Node *temp = head;
    Node *prev = nullptr;

   
    if (temp != nullptr && temp->data == key) 
    {
        head = temp->next;    
        delete temp;          
        return;
    }

  
    while (temp != nullptr && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }


    if (temp == nullptr) return;


    prev->next = temp->next;
    delete temp;
}



int main() 
{
    Node *head = nullptr;

  
    insertAtEnd(head, 'C');
    insertAtEnd(head, 'P');
    insertAtEnd(head, 'E');
    insertAtEnd(head, '0');
    insertAtEnd(head, '1');
    insertAtEnd(head, '0');

    cout << "Initial list: ";
    traversal(head); 


    insertAtHead(head, 'X');
    cout << "After inserting 'X' at head: ";
    traversal(head);

   
    insertAtEnd(head, 'X');
    cout << "After inserting 'X' at end: ";
    traversal(head);

 
    insertAfter(head->next, 'X');
    cout << "After inserting 'X' after the second node: ";
    traversal(head);


    deleteNode(head, '1');
    cout << "After deleting '1': ";
    traversal(head);

    return 0;
}


