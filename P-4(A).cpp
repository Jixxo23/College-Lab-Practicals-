#include <iostream>
#include <string>
using namespace std;

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int priority(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    string infix, postfix = "";
    char ch;

    cout << "Enter an infix expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix += pop();
            }

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && peek() != '(' &&
                   priority(peek()) >= priority(ch))
            {
                postfix += pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix += pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}