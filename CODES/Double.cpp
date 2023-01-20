#include <iostream>
using namespace std;
#include <conio.h>
int Max = 4;
int arr[4];
int front = -1;
int rear = -1;
int count = 0;

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0; 
    }
}
int isFull()
{
    if ((front == 0 && rear == Max - 1) || (front == rear + 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    cout<<"\n --THE ARRAY-- ";
    cout<<"\nElement   Index";
    int ch = 0;
    if (isEmpty() == 1)
    {
        cout<<"\n --EMPTY QUEUE-- ";
    }
    else if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            
            cout<<"\n"<<arr[i]<<"          "<<i;
        }
    }
    else
    {
        for (int i = front; i <= Max - 1; i++)
        {
            cout<<"\n"<<arr[i]<<"          "<<i;
        }
        for (int i = 0; i <= rear; i++)
        {
            
            cout<<"\n"<<arr[i]<<"          "<<i;
        }
    }
}

void EnqueueF()
{

    int flag = 0;
    int enq;
    if (isFull() == 1)
    {
        cout<<" --OVERFLOW-- ";
        flag = 1;
    }
    else if ((front == -1) && (rear == -1))
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = Max - 1;
    }
    else
    {
        front = front - 1;
    }
    if (flag == 0)
    {
        cout<<"ENTER THE ELEMENT TO ENQUEUE : ";
        count++;
        cin>>enq;
        arr[front] = enq;
    }
    display();
}

void EnqueueR()
{

    int flag = 0;
    int enq;
    if (isFull() == 1)
    {
        cout<<" --OVERFLOW-- ";
        flag = 1;
    }
    else if ((front == -1) && (rear == -1))
    {
        front = 0;
        rear = 0;
    }
    else if (rear == (Max - 1))
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    if (flag == 0)
    {
        cout<<"ENTER THE ELEMENT TO ENQUEUE : ";
        count++;
        cin>>enq;
        arr[rear] = enq;
    }
    display();
}

void DequeueF()
{
    if (isEmpty() == 1)
    {
      cout<<" --UNDERFLOW-- ";
    }
    else
    {
        int value = arr[front];
        count--;
        cout<<"1.VALUE RETURNED AFTER DEQUEUE IS : "<<value;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == Max - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }
    display();
}

void DequeueR()
{
    if (isEmpty() == 1)
    {
        cout<<" --UNDERFLOW-- ";
    }
    else
    {
        int value = arr[front];
        count--;
        cout<<"2.VALUE RETURNED AFTER DEQUEUE IS : "<<value;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = Max - 1;
    }
    else
    {
        rear = rear - 1;
    }
    display();
}

void size()
{
    if (isEmpty() == 1)
    {
        cout<<"\n --EMPTY QUEUE-- ";
    }
    else
    {
        cout<<" THE SIZE OF THE QUEUE IS : "<<count;
    }
}

int main()
{
    int temp;
    int n;
    int ch = 0;
    int sh = 0;
    cout<<"--THIS PROGRAME IS AN IMPLIMENTATION OF QUEUE ADT USING ARRAYS--\n";
    cout<<"\nEnter Your Choice: ";
    cout<<"\n1.Input Restricted\n2.Output Restricted\n";
    cin>>sh;

    while (ch != 6)
    {
        if (sh == 1)
        {

            cout<<"\nEnter Your Choice: ";
            cout<<"\n1. ENQUEUER \n2. DEQUEUER \n3. DEQUEUEF\n4. SIZE\n5. DISPLAY\n6. EXIT\n";
            cin>>ch;
            switch (ch)
            {
            case 1:
                EnqueueR();
                break;
            case 2:
                DequeueR();
                break;
            case 3:
                DequeueF();
                break;
            case 4:
                size();
                break;
            case 5:
                display();
                break;
            case 6:
                cout<<"Exit"<<endl;
                break;    
            default:
                cout<<"Invalid Choice";
                break;
            }
        }
        if (sh == 2)
        {
            cout<<"\nEnter Your Choice:";
            cout<<"\n1.ENQUEUEF\n2. ENQUEUER \n3. DEQUEUEF\n4. SIZE\n5. DISPLAY\n6. EXIT\n";
            cin>>ch;
            switch (ch)
            {

            case 1:
                EnqueueF();
                break;
            case 2:
                EnqueueR();
                break;
            case 3:
                DequeueF();
                break;
            case 4:
                size();
                break;
            case 5:
                display();
                break;
            case 6:
                cout<<"Exit"<<endl;
                break;    
            default:
                cout<<"Invalid Choice";
                break;
            }
        }
    }
}
