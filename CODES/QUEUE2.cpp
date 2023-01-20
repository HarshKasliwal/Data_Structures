#include <iostream>
using namespace std;
#define n 100
int queue[n];
int size = 0;
int rear = - 1;
int front = -1;
void enqueue() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1 )
      front = 0; 
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
      size++;
   }
}
void dequeue(){
   if (front == - 1 && rear == -1) {
      cout<<"Queue Underflow ";
   } 
   else if(front==rear) {
       front=rear=-1;
   }
   else{
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;
      size--;
   }
}
void display(){
   if (front == - 1 && rear == -1)
   cout<<"Queue is Empty"<<endl;
   else{
       for(int i=front; i<=rear; i++)
        cout<<queue[i]<<" ";
   }
   cout<<endl;
}
void get_front(){
    if (front == - 1 && rear == -1)
    cout<<"Queue is Empty"<<endl;
    else{
        cout<<queue[front];
    }
}
void get_rear(){
    if (front == - 1 && rear == -1)
    cout<<"Queue is Empty"<<endl;
    else{
        cout<<queue[rear];
    }
}
int main() {
   int ch;
   cout<<"1) ENQUEUE "<<endl;
   cout<<"2) DEQUEUE"<<endl;
   cout<<"3) GET FRONT"<<endl;
   cout<<"4) GET REAR"<<endl;
   cout<<"5) SIZE"<<endl;
   cout<<"6) DISPLAY"<<endl;
   cout<<"7) EXIT"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: enqueue();
         break;
         case 2: dequeue();
         break;
         case 3: get_front();
         break;
         case 4: get_rear();
         break;
         case 5:  cout<<"Size = "<<size;
                  cout<<endl;
         break;
         case 6:  display();
         break;
         case 7: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=7);
   return 0;
}