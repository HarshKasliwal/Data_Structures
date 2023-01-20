#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char item)
{
    if (top >= SIZE - 1)
    {
        cout << "Stack Overflow." << endl;
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

char pop()
{
    char item;

    if (top < 0)
    {
        cout << "Stack under flow: invalid infix expression" << endl;
        getchar();
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    cout<<"Sr.\tStack\tPostfix"<<endl;
    cout<<"0\t(\t"<<endl;
    int i, j;
    char item;
    char x;

    push('(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    item = infix_exp[i];
    int counter = 1;
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
            postfix_exp[j] = '\0';
        }
        else if (is_operator(item) == 1)
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                postfix_exp[j] = '\0';
                x = pop();
            }
            push(x);

            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                postfix_exp[j] = '\0';
                x = pop();
            }
        }
        else
        {
            cout << "Invalid infix Expression." << endl;
            getchar();
            exit(1);
        }
        i++;
        cout<<counter<<"\t"<<stack<<"\t"<<postfix_exp<<"\t"<<endl;
        counter++;
        item = infix_exp[i];
    }
    if (top > 0)
    {
        cout << "Invalid infix Expression." << endl;
        getchar();
        exit(1);
    }
    

    postfix_exp[j] = '\0';
}

int main()
{
    char infix[SIZE], postfix[SIZE];
    cout << "ASSUMPTION: The infix expression contains single letter variables and single digit constants only." << endl;
    cout << "Enter Infix expression : " << endl;
    gets(infix);

    InfixToPostfix(infix, postfix);
    cout << "Postfix Expression: " << endl;
    puts(postfix);

    return 0;
}