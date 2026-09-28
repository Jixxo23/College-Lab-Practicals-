#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *first = NULL;

Node *createNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int value) {
    Node *newNode = createNode(value);

    if (first == NULL) {
        first = newNode;
        newNode->next = first;
        return;
    }

    Node *temp = first;

    while (temp->next != first)
        temp = temp->next;

    newNode->next = first;
    temp->next = newNode;
    first = newNode;
}

void insertEnd(int value) {
    Node *newNode = createNode(value);

    if (first == NULL) {
        first = newNode;
        newNode->next = first;
        return;
    }

    Node *temp = first;

    while (temp->next != first)
        temp = temp->next;

    newNode->next = first;
    temp->next = newNode;
}

void insertAfter(int key, int value) {
    if (first == NULL) {
        cout << "List empty!";
        return;
    }

    Node *temp = first;

    do {
        if (temp->data == key) {
            Node *newNode = createNode(value);

            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }

        temp = temp->next;
    } while (temp != first);

    cout << "Node not found!";
}

void deleteFirst() {
    if (first == NULL) {
        cout << "List empty!";
        return;
    }

    if (first->next == first) {
        delete first;
        first = NULL;
        return;
    }

    Node *temp = first;
    Node *last = first;

    while (last->next != first)
        last = last->next;

    first = first->next;
    last->next = first;

    delete temp;
}

void deleteLast() {
    if (first == NULL) {
        cout << "List empty!";
        return;
    }

    if (first->next == first) {
        delete first;
        first = NULL;
        return;
    }

    Node *temp = first;

    while (temp->next->next != first)
        temp = temp->next;

    Node *del = temp->next;
    temp->next = first;

    delete del;
}

void deleteAfter(int key) {
    if (first == NULL) {
        cout << "List empty!";
        return;
    }

    Node *temp = first;

    do {
        if (temp->data == key) {
            Node *del = temp->next;

            if (del == first)
                first = first->next;

            temp->next = del->next;
            delete del;
            return;
        }

        temp = temp->next;
    } while (temp != first);

    cout << "Node not found!";
}

void display() {
    if (first == NULL) {
        cout << "List empty!";
        return;
    }

    Node *temp = first;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != first);

    cout << "BACK TO FIRST";
}

int main() {
    int choice;

    while (1) {
        cout << "\n\n1. Insert Beginning";
        cout << "\n2. Insert End";
        cout << "\n3. Insert After Given Node";
        cout << "\n4. Delete First Node";
        cout << "\n5. Delete Last Node";
        cout << "\n6. Delete Node After Given Node";
        cout << "\n7. Display";
        cout << "\n8. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                int value;
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(value);
                break;
            }

            case 2: {
                int value;
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;
            }

            case 3: {
                int key, value;
                cout << "Enter given node: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                insertAfter(key, value);
                break;
            }

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6: {
                int key;
                cout << "Enter given node: ";
                cin >> key;
                deleteAfter(key);
                break;
            }

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                cout << "Invalid choice!";
        }
    }

    return 0;
}