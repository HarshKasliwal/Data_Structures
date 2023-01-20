// Linear Search:
#include <iostream>
#include <conio.h>
using namespace std;
#define size 10
int main()
{
    int arr[size], n, i, num, found = 0;
    cout << "\n Enter the number of elements:";
    cin >> n;
    cout << "Enter elements:";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter the element to be searched:\n";
    cin >> num;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            found = 1;
            cout << "Found at " << i + 1;
            break;
        }
    }
    if (found == 0)
    {
        cout << "Element not found";
    }
    return 0;
}