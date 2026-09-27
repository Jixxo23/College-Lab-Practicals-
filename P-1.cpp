#include <iostream>
using namespace std;

void insertion(int arr[100], int &n)
{
    int elem, pos;

    cout << "Enter the element to add: ";
    cin >> elem;

    cout << "Enter position: ";
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = elem;
    n++;

    cout << "Element inserted successfully." << endl;
}

void deletion(int arr[100], int &n)
{
    int ele;
    bool found = false;

    cout << "Enter the element to delete: ";
    cin >> ele;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            found = true;

            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            n--;
            cout << "Element deleted successfully." << endl;
            break;
        }
    }

    if (!found)
        cout << "Value not found!" << endl;
}

void searching(int arr[100], int n)
{
    int ele;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> ele;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            cout << "Found the element at position: " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element not found!" << endl;
}

void traverse(int arr[100], int n)
{
    cout << "Array = ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int arr[100], n;

    cout << "Enter total number: ";
    cin >> n;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    bool running = true;

    while (running)
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Searching" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertion(arr, n);
                break;

            case 2:
                deletion(arr, n);
                break;

            case 3:
                searching(arr, n);
                break;

            case 4:
                traverse(arr, n);
                break;

            case 5:
                running = false;
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}