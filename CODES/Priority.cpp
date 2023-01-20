#include <iostream>
using namespace std;

void enqueue();
void dequeue();
void peekfront();
void peekrear();
void Size();
void display();

#define max 5
int queue[max], choice, front = -1, rear = -1, value;

int main()
{

    cout<<"\nThis program is an implementation of Queue ADT using arrays\n";

    while (choice != 7)
    {
        cout<<"\nWhat operation do you want to perform?\n";
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.Front\n";
        cout<<"4.Rear\n";
        cout<<"5.Size\n";
        cout<<"6.Display\n";
        cout<<"7.Exit\n";
        cout<<"Enter your choice:"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peekfront();
            break;

        case 4:
            peekrear();
            break;

        case 5:
            Size();
            break;

        case 6:
            display();
            break;

        case 7:
            break;
        }
    }

    return 0;
}

void dequeue()
{
    int value;
    if ((front == -1) && (rear == -1))
    {
        cout<<"\nQueue is empty\n";
    }
    else
    {
        value = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            int pos = 0;
            int p = queue[0];
            for (int i = 1; i <= rear; i++)
            {
                if (queue[i] > p)
                {
                    pos = i;
                    p = queue[i];
                }
            }
            value = p;
            for (int i = pos; i < rear; i++)
            {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
        cout<<value<< " is deleted from the queue";
    }
}

void enqueue()
{

    int value;
    if (rear == max - 1)
    {
        cout<<"\nQueue is full\n";
    }
    else
    {
        cout<<"Enter the value you want to add:"<<endl;
        cin>>value;
        if ((front == -1) && (rear == -1))
        {
            front = 0;
            rear = 0;
            queue[rear] = value;
           cout<<value << " is added to the queue";
        }
        else
        {
            rear++;
            queue[rear] = value;
            cout<<value << " is added to the queue";
        }
    }
}

void peekfront()
{
    if ((front == -1) && (rear == -1))
    {
        cout<<"\nUNDERFLOW\n";
    }
    else
    {
        cout<<queue[front]<< " is at the front end\n";
    }
}

void peekrear()
{
    if ((front == -1) && (rear == -1))
    {
        cout<<"\nUNDERFLOW\n";
    }
    else
    {
        cout<<queue[rear]<< " is at the rear end\n";
    }
}

void Size()
{
    cout<<"Size==> "<<(rear - front) + 1;
}

void display()
{
    if ((front == -1) && (rear == -1))
    {
        cout<<"\nUNDERFLOW\n";
    }
    else
    {
        cout<<"\nThe elements in the queue are:";
        for (int i = front; i <= rear; i++)
        {
            cout<<" "<<queue[i];
        }
        cout<<"\n";
    }
}
