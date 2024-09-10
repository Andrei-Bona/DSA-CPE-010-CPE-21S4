#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        
        double area();
        double perimeter();
        string type();
        
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
        
};

Triangle::Triangle(double A, double B, double C) 
{
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C) 
{
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle() 
{
    return (totalAngle == 180);
}

double Triangle::area()
{
    double s = (angleA + angleB + angleC) / 2;
    double area = sqrt(s * (s - angleA) * (s - angleB) * (s - angleC));//Heron's Formula
    return area;
}

double Triangle::perimeter()
{
    return totalAngle;
}

string Triangle::type()
{
    if (angleA > 90 || angleB > 90 || angleC > 90)
        return "obtuse-angled";
    else if (angleA == 90 || angleB == 90 || angleC == 90)
        return "right-angled";
    else
        return "acute-angled";    
}
int main()
{

    Triangle set1(40, 30, 110);
    if(set1.validateTriangle())
    {
        cout << "The shape is a valid triangle.\n";
        cout << "The area of the triangle is: "<<set1.area()<<"\n";
        cout << "The perimeter of the triangle is: "<<set1.perimeter()<<"\n";
        cout << "The triangle is " << set1.type() << "\n";
    } 
        else 
        {
            cout << "The shape is NOT a valid triangle.\n";
        }
  
    
    return 0;
}

