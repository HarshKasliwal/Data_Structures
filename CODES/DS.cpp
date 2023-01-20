#include <iostream>
using namespace std;
int stack[10], n = 10, top = -1;
void push(int val)
{
   if (top >= n - 1)
   {
      cout << "Stack Overflow" << endl;
   }
   else
   {
      top++;
      stack[top] = val;
   }
}
void pop()
{
   if (top <= -1)
   {
      cout << "Stack Underflow" << endl;
   }
   else
   {
      cout << "The popped element is " << stack[top] << endl;
      top--;
   }
}
void peek()
{
   if (top <= -1)
   {
      cout << "Stack Underflow" << endl;
   }
   else
   {
      cout << "The top most element is : " << stack[top] << endl;
   }
}
void size()
{
   int count = 0;
   if (top <= -1)
   {
      cout << "Stack Underflow" << endl;
   }
   else
   {
      for (int i = top; i >= 0; i--)
      {
         count++;
      }
      cout << "Size of the stack is:" << count << endl;
   }
}

void display()
{
   if (top >= 0)
   {
      cout << "Stack elements are:";
      for (int i = top; i >= 0; i--)
         cout << stack[i] << " ";
      cout << endl;
   }
   else
      cout << "Stack is empty";
}
int main()
{
   int ch, val;
   cout << "1) Push in stack" << endl;
   cout << "2) Pop from stack" << endl;
   cout << "3) Peek in stack" << endl;
   cout << "4) Size of the element" << endl;
   cout << "5) Display stack" << endl;
   cout << "6) Exit" << endl;
   do
   {
      cout << "Enter choice: " << endl;
      cin >> ch;
      switch (ch)
      {
      case 1:
      {
         cout << "Enter value to be pushed:" << endl;
         cin >> val;
         push(val);
         break;
      }
      case 2:
      {
         pop();
         break;
      }
      case 3:
      {
         peek();
         break;
      }

      case 4:
      {
         size();
         break;
      }
      case 5:
      {
         display();
         break;
      }
      case 6:
      {
         cout << "Exit" << endl;
         break;
      }
      default:
      {
         cout << "Invalid Choice" << endl;
      }
      }
   } while (ch != 6);
   return 0;
}