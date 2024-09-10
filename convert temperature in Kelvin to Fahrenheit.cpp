#include <iostream>
using namespace std;

double tempK, tempF;

double convertTemp(double tempK)
{
    return (9.0/5.0)*(tempK - 273.15) + 32.0;
}

int main ()
{
    cout << "Enter the temperature: ";
    cin >> tempK;

    tempF = convertTemp (tempK);
    cout << "The temperature from Kelvin to Fahrenheit: " <<tempF;
    return 0;
}

