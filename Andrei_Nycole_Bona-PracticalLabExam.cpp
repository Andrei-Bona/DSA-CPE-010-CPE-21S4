/*
Write a c++ program to create an array of 10
integers and display the array items. Access
individual elements through indexes and compute 
for sum 
*/

#include <iostream>
using namespace std;

int main() 
{
    int i;
    int sum;
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    //output of 10 integers
    cout << "Numbers in array:" <<endl;
    for (int i = 0; i < 10; i++) 
    {
      cout<<array[i]<<", ";
    }
    cout<<endl;
    //summation of all integers
    while(i<10)
    {
        sum += array[i];
        i++;
    }
    
    cout<<endl;
    cout<<"Sum of 10 integers: "<<sum;
    return 0;
}
