#include <iostream>
#include <string>
#define MAX 100
using namespace std;

char arr[MAX];
int top = -1;

void push(char ch) 
{
    if (top >= (MAX - 1)) 
    {
        cout << "Stack Overflow\n";
    } else 
    {
        arr[++top] = ch;
    }
}

char pop() 
{
    if (top < 0) {
        cout << "Stack Underflow\n";
        return '\0';
    } else {
        return arr[top--];
    }
}

bool isEmpty() 
{
    return top == -1;
}

bool isBalancedArray(string expr) 
{
    for (char &ch : expr) 
    {
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (isEmpty()) 
            {
                return false;
            }
            char topChar = pop();
            if ((ch == ')' && topChar != '(') || (ch == '}' && topChar != '{') || (ch == ']' && topChar != '[')) 
            {
                return false;
            }
        }
    }
    return isEmpty();
}

int main() 
{
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);
    if (isBalancedArray(expr)) 
    {
        cout << "Expression is balanced\n";
    } else 
    {
        cout << "Expression is not balanced\n";
    }
    return 0;
}
