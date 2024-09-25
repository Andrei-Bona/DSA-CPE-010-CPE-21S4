//Stack
/*
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
*/

//Queue (not finish)
/*
#include <iostream>
#include <queue>
using namespace std;

void display(queue<string>pl)
{
    while (!pl.empty())
    {
        cout<<pl.front()<<endl;
        pl.pop();  
    }

void check(queue<string>pl)
{
    if (pl.size() == 3)
    {
        cout<<"Queue is Full";
    }
}

int main ()
{
    queue<string> pl;

    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    cout<<"Initial Queue:"<<endl;
    display(pl);
    //check(pl);

    
    //*cout<<"Final Queue:"<<endl;
    pl.pop();
    cout<<pl.front();*/

    return 0;
}
*/



