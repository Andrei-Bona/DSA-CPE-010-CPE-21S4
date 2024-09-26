//Stack
#include <iostream>
#include <stack>
using namespace std;

void display(stack<string>pl)
{
    while (!pl.empty())
    {
        cout<<pl.top()<<endl;
        pl.pop();
    }
}

int main ()
{
    stack<string> pl;
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    cout<<"Initial Stack:"<<endl;
    display(pl);
    
    cout<<endl;
    
    cout<<"Final Stack:"<<endl;
    pl.pop();
    cout<<pl.top();


    return 0;
}

// Queue
#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 3;

void display(queue<string> pl)
{
    while (!pl.empty())
    {
        cout << pl.front() << endl;
        pl.pop();
    }
}

int main()
{
    queue<string> pl;
    
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");

    if (pl.size() == MAX_SIZE)
    {
        cout << "The queue is full" << endl;
    }

    cout << "Initial Queue:" << endl;
    display(pl);


    if (pl.size() < MAX_SIZE)
    {
        pl.push("C#");
    }
    else
    {
        cout << "Cannot add 'C#', the queue is full" << endl;
    }


    cout << "Final Queue after pop:" << endl;
    pl.pop(); 
    display(pl);

    return 0;
}

