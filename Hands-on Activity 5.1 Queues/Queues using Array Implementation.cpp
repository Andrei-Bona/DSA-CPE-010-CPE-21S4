#include <iostream>
#include <string>
using namespace std;

class Queue 
{
    private:
        string* arr;     
        int capacity;     
        int front;      
        int rear;        
        int size;   
        
    public:
    
        Queue(int cap = 10) 
        {
            capacity = cap;
            arr = new string[capacity];
            front = 0;
            rear = -1;
            size = 0;
        }


    ~Queue() 
    {
        delete[] arr;
    }


    Queue(const Queue& other) 
    {
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        size = other.size;
        arr = new string[capacity];
        for (int i = 0; i < capacity; i++) 
        {
            arr[i] = other.arr[i];
        }
    }


    Queue& operator=(const Queue& other) 
    {
        if (this != &other) 
        {
            delete[] arr;  

            capacity = other.capacity;
            front = other.front;
            rear = other.rear;
            size = other.size;
            arr = new string[capacity];
            for (int i = 0; i < capacity; i++) 
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    bool isEmpty() const 
    {
        return size == 0;
    }


    int getSize() const 
    {
        return size;
    }

    void clear() 
    {
        front = 0;
        rear = -1;
        size = 0;
    }


    string getFront() const 
    {
        if (isEmpty()) 
        {
            throw out_of_range("Queue is empty");
        }
        return arr[front];
    }


    string getBack() const 
    {
        if (isEmpty()) 
        {
            throw out_of_range("Queue is empty");
        }
        return arr[rear];
    }


    void enqueue(const string& name) 
    {
        if (size == capacity) 
        {
            throw overflow_error("Queue overflow");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = name;
        size++;
    }


    void dequeue() 
    {
        if (isEmpty()) 
        {
            throw underflow_error("Queue underflow");
        }
        front = (front + 1) % capacity;
        size--;
    }


    void display() const 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) 
        {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() 
{

    Queue q(5);


    cout << "Enqueueing 'Vincent', 'Frederick', 'Andrei'." << endl;
    q.enqueue("Vincent");
    q.enqueue("Frederick");
    q.enqueue("Andrei");
    q.display();


    cout << "\nFront: " << q.getFront() << endl;
    cout << "Back: " << q.getBack() << endl;

    cout << "\nEnqueueing 'Anna', 'Bona'." << endl;
    q.enqueue("Anna");
    q.enqueue("Bona");
    q.display();

    cout << "\nDequeuing one element." << endl;
    q.dequeue();
    q.display();

    cout << "\nClearing the queue." << endl;
    q.clear();
    q.display();

    cout << "\nTesting copy constructor." << endl;
    q.enqueue("Nycole");
    q.enqueue("Bona");
    Queue q2 = q;
    q2.display();

    cout << "\nTesting copy assignment operator." << endl;
    Queue q3;
    q3 = q2;
    q3.display();

    return 0;
}
