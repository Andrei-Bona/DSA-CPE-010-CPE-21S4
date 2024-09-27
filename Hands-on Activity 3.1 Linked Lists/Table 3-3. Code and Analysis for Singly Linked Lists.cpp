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
    insertAtEnd(head, '1');
    insertAtEnd(head, '0');
    insertAtEnd(head, '1');
 
    cout << "Initial list: ";
    traversal(head);

   
    insertAtHead(head, 'G');
    cout << "After inserting 'G' at head: ";
    traversal(head);

  
    Node *current = head;
    while (current != nullptr && current->data != 'P') 
    {
        current = current->next;
    }
    if (current != nullptr) 
    {
        insertAfter(current, 'E');
    }
    cout << "After inserting 'E' after 'P': ";
    traversal(head);

  
    deleteNode(head, 'C');
    cout << "After deleting 'C': ";
    traversal(head);

  
    deleteNode(head, 'P');
    cout << "After deleting 'P': ";
    traversal(head);

 
    cout << "Final list: ";
    traversal(head);

    return 0;
}


