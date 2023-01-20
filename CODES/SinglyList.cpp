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
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);
struct node *backtraversal(struct node *);
struct node *no_of_nodes(struct node *);
struct node *search(struct node *);
struct node *del_specif(struct node *);
int main(int argc, char *argv[])
{
    int option;
    do
    {
        cout << "\n1.LIST";
        cout << "\n2.INSERT IN BEGINNING";
        cout << "\n3.INSERT AT END";
        cout << "\n4.INSERT BEFORE A GIVEN NODE";
        cout << "\n5.DELETE FROM BEGINNING";
        cout << "\n6.DELETE FROM END";
        cout << "\n7.DELETE NODE BEFORE A SPECIFIED LOCATION ";
        cout << "\n8.FORWARD TRAVERSAL";
        cout << "\n9.BACKWARD TRAVERSAL";
        cout << "\n10.SORTING";
        cout << "\n11.COUNT NUMBER OF NODES";
        cout << "\n12.SEARCH AN ELEMENT";
        cout << "\n13.EXIT";
        cout << "\n\nENTER YOUR OPTION : ";
        cin >> option;
        switch (option)
        {
        case 1:
            start = list(start);
            cout << "\n--LINKED LIST CREATED--";
            break;
        case 2:
            start = insert_beg(start);
            break;
        case 3:
            start = insert_end(start);
            break;
        case 4:
            start = insert_before(start);
            break;
        case 5:
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        case 7:
            start = del_specif(start);
            break;
        case 8:
            start = display(start);
            break;
        case 9:
            start = backtraversal(start);
            break;
        case 10:
            start = sort_list(start);
            break;
        case 11:
            start = no_of_nodes(start);
            cout << "\nNUMBER OF NODES ARE : " << count;
            break;
        case 12:
            start = search(start);
            break;
        }
    } while (option != 13);
    getch();
    return 0;
}
struct node *list(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    cout << "ENTER -1 TO END!"<<endl;
    cout << "ENTER THE DATA :";
    cin >> num;
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        cout << "\n ENTER THE DATA : ";
        cin >> num;
    }
    return start;
}
struct node *display(struct node *start)
{
    if (flag == 1)
    {
        cout << "\n\n -- EMPTY LIST -- \n\n";
    }
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        cout << "\t "<< ptr->data;
        ptr = ptr->next;
    }
    return start;
}
struct node *search(struct node *start)
{
    int num;
    int flag = 0;
    cout << "ENTERR THE ELEMEMENT TO BE SEARCHED :";
    cin >> num;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->data == num)
        {
            cout << "\n\nNUMBER IS FOUND!\n\n";
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag != 1)
    {
        cout << "\n\nNUMBER NOT FOUND! :(\n\n";
    }
    return start;
}
struct node *no_of_nodes(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        count = count + 1;
        ptr = ptr->next;
    }
    return start;
}
struct node *backtraversal(struct node *start)
{
    struct node *prev = NULL;
    struct node *current = start;
    struct node *nextt = NULL;
    while (current != NULL)
    {
        nextt = current->next;
        current->next = prev;
        prev = current;
        current = nextt;
    }
    start = prev;
};
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    cout << "\n ENTER THE DATA : ";
    cin >> num;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    cout << "\n ENTER THE DATA ";
    cin >> num;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, value;
    cout << "ENTER THE DATA ";
    cin >> num;
    cout << "ENTER THE VALUE BEFORE WHICH THE DATA IS TO BE INSERTED ";
    cin >> value;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}
struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    cout << "ENTER THE VALUE TO BE DELETED";
    cin >> val;
    ptr = start;
    if (ptr->data == val)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}
struct node *del_specif(struct node *start)
{
    start = no_of_nodes(start);
    int loc;
    struct node *ptr, *preptr;
    ptr = start;
    cout << "ENTER THE LOCATION ";
    cin >> loc;
    while (ptr->next != NULL)
    {
        if (loc + 1 == count)
        {
            preptr = ptr;
        }
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}
struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}