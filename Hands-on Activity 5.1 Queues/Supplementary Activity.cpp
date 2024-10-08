#include <iostream>
#include <string>
using namespace std;


class Job
{
    public:
        int jobID;
        string userName;
        int numPages;


    Job(int id, string user, int pages)
    {
        jobID = id;
        userName = user;
        numPages = pages;
    }


    void displayJob() {
        cout << "Job ID: " << jobID << ", User: " << userName << ", Pages: " << numPages << endl;
    }
};


class Printer
{
    private:
        Job** jobQueue;  
        int capacity;
        int front;
        int rear;
        int size;


public:
    Printer(int cap = 10)
    {
        capacity = cap;
        jobQueue = new Job*[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }


    ~Printer()
    {
        for (int i = 0; i < size; ++i)
        {
            delete jobQueue[(front + i) % capacity];
        }
        delete[] jobQueue;
    }


    bool isFull() const
    {
        return size == capacity;
    }


    bool isEmpty() const
    {
        return size == 0;
    }


    void addJob(int jobID, string userName, int numPages)
    {
        if (isFull())
        {
            cout << "Printer queue is full. Cannot add more jobs.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        jobQueue[rear] = new Job(jobID, userName, numPages);
        size++;
        cout << "Added job: " << jobID << " by " << userName << " with " << numPages << " pages." << endl;
    }


    void processJob()
    {
        if (isEmpty())
        {
            cout << "No jobs to process.\n";
            return;
        }
        Job* currentJob = jobQueue[front];
        front = (front + 1) % capacity;
        size--;


        cout << "Processing: ";
        currentJob->displayJob();
        delete currentJob;
    }


    void processAllJobs()
    {
        while (!isEmpty())
        {
            processJob();
        }
    }
};


int main()
{
    Printer printer(5);  
    printer.addJob(1, "Vincent", 10);
    printer.addJob(2, "Frederick", 20);
    printer.addJob(3, "Andrei", 30);
    printer.addJob(4, "Anna", 40);
    printer.addJob(5, "Bona", 50);

    printer.addJob(6, "John", 60);

    printer.processJob();
    printer.processJob();  
    printer.addJob(6, "Doe", 10);

    printer.processAllJobs();

    return 0;
}
