#include <iostream>
using namespace std;

int num1, num2, null;

int main ()
{
    cout << "Enter your first Number:";
    cin >> num1;
    cout << "Enter your second Number:";
    cin >> num2;
	cout << "Before the swap:" <<endl;
	cout << num1<<endl;
	cout << num2<<endl;
	    
	null = num1;
	num1 = num2;
	num2 = null;
	
	cout << "After the swap:" <<endl;
	cout << num1<<endl;
	cout << num2<<endl;

    return 0;
}

