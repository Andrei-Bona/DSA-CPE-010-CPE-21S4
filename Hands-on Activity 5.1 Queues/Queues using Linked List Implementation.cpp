#include <iostream>
#include <string>
using namespace std;


class Node
{
    public:
        string name;
        Node* next;
   
        Node(string val)
        {
            name = val;
            next = nullptr;
        }
};


class Queue
{
    private:
        Node* front;
        Node* rear;
   
    public:
        Queue()
        {
            front = nullptr;
            rear = nullptr;
        }


    void enqueue(string name)
    {
        Node* newNode = new Node(name);
        if (rear == nullptr)
        {
            front = rear = newNode;
        } else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }


    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;


        if (front == nullptr)
        {
            rear = nullptr;
        }


        delete temp;
    }


    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr)
        {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    bool isEmpty()
    {
        return front == nullptr;
    }
};


int main()
{
    Queue q;


    cout << "Inserting 'Vincent' into an empty queue." << endl;
    q.enqueue("Vincent");
    q.display();


    cout << "\nInserting 'Frederick' into a non-empty queue." << endl;
    q.enqueue("Frederick");
    q.display();


    cout << "\nInserting 'Andrei' and 'Anna' into the queue." << endl;
    q.enqueue("Andrei");
    q.enqueue("Anna");
    q.display();


    cout << "\nDeleting the front item (queue has more than one item)." << endl;
    q.dequeue();
    q.display();


    cout << "\nDeleting items until only one is left." << endl;
    q.dequeue();
    q.display();


    cout << "\nDeleting the last remaining item from the queue." << endl;
    q.dequeue();
    q.display();


    cout << "\nAttempting to delete from an empty queue." << endl;
    q.dequeue();


    return 0;
}
