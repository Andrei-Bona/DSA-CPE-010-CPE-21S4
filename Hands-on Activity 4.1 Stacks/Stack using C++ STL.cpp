#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalancedSTL(string expr) 
{
    stack<char> stack;

    for (char &ch : expr) 
    {
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (stack.empty()) 
            {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() 
{
    string expr;
    
    cout << "Enter an expression: ";
    getline(cin, expr);
    
    if (isBalancedSTL(expr)) {
        cout << "Expression is balanced\n";
    } else {
        cout << "Expression is not balanced\n";
    }
    return 0;
}
