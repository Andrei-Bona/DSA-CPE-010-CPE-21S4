#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    char data;
    Node* next;
};

Node* top = nullptr;

void push(char ch) 
{
    Node* node = new Node();
    node->data = ch;
    node->next = top;
    top = node;
}

char pop() 
{
    if (top == nullptr) 
    {
        cout << "Stack Underflow\n";
        return '\0';
    } else {
        Node* temp = top;
        top = top->next;
        char popped = temp->data;
        delete temp;
        return popped;
    }
}

bool isEmpty() 
{
    return top == nullptr;
}

bool isBalancedLinkedList(string expr) 
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
            if ((ch == ')' && topChar != '(') || (ch == '}' && topChar != '{') || (ch == ']' && topChar != '[')) {
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
    if (isBalancedLinkedList(expr)) 
    {
        cout << "Expression is balanced\n";
    } else 
    {
        cout << "Expression is not balanced\n";
    }
    return 0;
}
