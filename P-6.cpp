#include <iostream>
using namespace std;

struct node
{
    int info;
    node* next;
};

node* First = NULL;

node* create_node(int x)
{
    node* temp = new node;

    temp->info = x;
    temp->next = NULL;

    return temp;
}

void insert_first(int x)
{
    node* temp;

    temp = create_node(x);

    temp->next = First;
    First = temp;
}

void insert_last(int x)
{
    node* t;
    node* p;

    t = create_node(x);

    if (First == NULL)
    {
        First = t;
    }
    else
    {
        p = First;

        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = t;
    }
}

void insert(int pos, int x)
{
    node* t;
    node* p;
    int c = 1;

    t = create_node(x);

    if (pos == 1)
    {
        t->next = First;
        First = t;
        return;
    }

    if (First == NULL)
    {
        cout << "List is empty." << endl;
        delete t;
        return;
    }

    p = First;

    while (c < pos - 1 && p->next != NULL)
    {
        p = p->next;
        c++;
    }

    if (c != pos - 1)
    {
        cout << "Invalid position." << endl;
        delete t;
        return;
    }

    t->next = p->next;
    p->next = t;
}

void display()
{
    node* p = First;

    if (First == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Linked List: ";

    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }

    cout << endl;
}

int main()
{
    int ch, x, pos;

    while (1)
    {
        cout << "\n1. Insert at first";
        cout << "\n2. Insert at last";
        cout << "\n3. Insert at position";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> x;
                insert_first(x);
                break;

            case 2:
                cout << "Enter the element to be inserted: ";
                cin >> x;
                insert_last(x);
                break;

            case 3:
                cout << "Enter the position and element to be inserted: ";
                cin >> pos >> x;
                insert(pos, x);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program is ended." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }
}