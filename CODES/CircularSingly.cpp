#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int flag = 0;
int count = 0;
struct node *start = NULL;
struct node *list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
void backtraversal(struct node *);
struct node *nodes(struct node *);
int main(int argc, char *argv[])
{
    int option;
    do
    {
        cout<<"\n1.LIST ";
        cout<<"\n2.ADD NODE IN THE BEGINING";
        cout<<"\n3.ADD NODE IN THE END";
        cout<<"\n4.DELETE A NODE FROM BEGINNING";
        cout<<"\n5.DELETE A NODE FROM END";
        cout<<"\n6.DISPLAY";
        cout<<"\n7.DISPLAY REVERSE";
        cout<<"\n8.COUNT THE NUMBER OF NODES ";
        cout<<"\n9.EXIT";
        cout<<"\n\nENTER YOUR OPTION : ";
        cin>>option;
        switch (option)
        {
        case 1:
            start = list(start);
            cout<<"\n--LINKED LIST CREATED--";
            break;
        case 2:
            start = insert_beg(start);
            break;
        case 3:
            start = insert_end(start);
            break;
        case 4:
            start = delete_beg(start);
            break;
        case 5:
            start = delete_end(start);
            break;
        case 6:
            start = display(start);
            break;
        case 7:
            backtraversal(start);
            break;
        case 8:
            start = nodes(start);
            cout<<"THE NUMBER OF NODES IN THE LINKED LIST ARE : "<<count;
            break;
        }
    } while (option != 9);
    getch();
    return 0;
}
struct node *list(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    cout<<"ENTER -1 TO END!"<<endl;
    cout<<"\nENTER THE DATA :";
    cin>>num;
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node; // new node ka address
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = start;
        }
        cout<<"\nENTER THE DATA : ";
        cin>>num;
    }
    return start;
}
struct node *display(struct node *start)
{
    if (flag == 1)
    {
        cout<<"\n\n  EMPTY LIST  \n\n";
    }
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        cout<<"\t "<<ptr->data;
        ptr = ptr->next;
    }
    cout<<"\t "<<ptr->data;
    return start;
}
void backtraversal(struct node *ptr)
{
    if (ptr->next != start)
    {
        backtraversal(ptr->next);
    }
    cout<<" "<< ptr->data<<"\t";
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    cout<<"\nENTER THE DATA : ";
    cin>>num;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    cout<<"\nENTER THE DATA ";
    cin>>num;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
}
struct node *nodes(struct node *start)
{
    struct node *ptr;
    ptr = start->next;
    count = 1;
    while (ptr != start)
    {
        count = count + 1;
        ptr = ptr->next;
    }
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}