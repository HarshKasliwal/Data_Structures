//Evaluation of postfix expression

#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 100

int stack[SIZE];
int Top = -1;
void push(char Item)
{
	if (Top >= SIZE - 1)
	{
		cout << "\nStack Overflow.";
	}
	else
	{
		Top = Top + 1;
		stack[Top] = Item;
	}
}

void push1(int y)
{
	stack[++Top] = y;
}

void get_stack()
{
	int i;
	for (i = 0; i <= Top; i++)
	{
		cout << stack[i];
		cout << " ";
	}
}

char pop()
{
	char Item;
	if (Top < 0)
	{
		cout << "Stack Under Flow: Invalid Infix Expression";
		getchar();
		exit(1);
	}
	else
	{
		Item = stack[Top];
		Top = Top - 1;
		return (Item);
	}
}
int pop1()
{
	return stack[Top--];
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
	int i, k;
	char Item;
	char x;

	push('(');
	strcat(infix_exp, ")");

	i = 0;
	k = 0;
	Item = infix_exp[i];
	while (Item != '\0')
	{
		if (Item == '(')
		{
			push(Item);
		}
		else if (isalnum(Item))
		{
			postfix_exp[k] = Item;
			k++;
		}
		else if (is_operator(Item) == 1)
		{
			x = pop();
			while (is_operator(x) == 1 && precedence(x) >= precedence(Item))
			{
				postfix_exp[k] = x;
				k++;
				x = pop();
			}
			push(x);

			push(Item);
		}
		else if (Item == ')')
		{
			x = pop();
			while (x != '(')
			{
				postfix_exp[k] = x;
				k++;
				x = pop();
			}
		}
		else
		{
			cout << "\nInvalid Infix Expression.\n";
			getchar();
			exit(1);
		}
		i++;

		Item = infix_exp[i];
	}
	if (Top > 0)
	{
		cout << "\nInvalid Infix Expression.\n";
		getchar();
		exit(1);
	}
	postfix_exp[k] = '\0';
}

int main()
{
	int i, ch;
	char exp[SIZE];
	char *a;
	int n1, n2, n3, num;
	char infix[SIZE], postfix[SIZE];
	cout << "You can enter infix or postfix expression, choose an option\n";
	cout << "1. Infix expression\n2. Postfix Expression\n\nEnter an Option:    ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		for (i = 0; i < SIZE; i++)
		{
			postfix[i] = '\0';
		}
		cout << "\nYou have chosen 1, Enter an infix expression:    ";
		cin >> infix;
		InfixToPostfix(infix, postfix);
		cout << "\n";
		cout << "Resultant postfix expression:    ";
		puts(postfix);
		a = postfix;
		break;
	case 2:
		cout << "Enter Postfix Expression : " << endl;
		cin >> postfix;
		a = postfix;
		break;
	}

	cout << "\nToken\tStack\n";
	char token;
	while (*a != '\0')
	{
		if (isdigit(*a))
		{
			num = *a - '0';
			token = *a;
			push1(num);
		}
		else
		{
			n1 = pop1();
			n2 = pop1();
			switch (*a)
			{
			case '+':
			{
				n3 = n1 + n2;
				token = '+';
				break;
			}
			case '-':
			{
				n3 = n2 - n1;
				token = '-';
				break;
			}
			case '*':
			{
				n3 = n1 * n2;
				token = '*';
				break;
			}
			case '/':
			{
				n3 = n2 / n1;
				token = '/';
				break;
			}
			}
			push1(n3);
		}
		cout << " \n " << token << "\t";
		get_stack();
		cout << " \n ";

		a++;
	}
	cout << "Final Result: " << pop1();
	return 0;
}