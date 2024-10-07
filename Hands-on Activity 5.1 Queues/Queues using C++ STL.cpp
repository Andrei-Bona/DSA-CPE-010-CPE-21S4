#include <iostream>
#include <string>
#include <queue>
using namespace std;

string array[] = {"Vincent", "Frederick", "Andrei", "Anna"}; 
int i = 0;

void display(queue <string> students)
{
    while (!students.empty())
    {
        cout << students.front() << endl;
        students.pop();
    }
    cout <<"\n";
}

int main()
{
    queue <string> students;

    cout << "The students in queue is :\n";
    
    for (i = 0; i < 4; i++)
    {
        students.push(array[i]);
    }
    display(students);
    
    cout << "students.empty() : " << students.empty() << "\n";
    cout << "students.size() : " << students.size() << "\n";
    cout << "students.front() : " << students.front() << "\n";
    cout << "students.back() : " << students.back() << "\n";
    cout <<"\n";
    cout << "students.pop() : \n";
    students.pop();
    display(students);

    students.push("Bona");
    cout << "The students in queue is:\n";
    display(students);

    
    return 0;
}
