#include <iostream>
using namespace std;

int main()
{
    int arr[100], n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int *ptr = arr + n - 1;

    cout << "Array elements in reverse order are: ";

    for (int i = 0; i < n; i++)
    {
        cout << *ptr << " ";
        ptr--;
    }

    return 0;
}