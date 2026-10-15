#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *root = NULL;

Node* createNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void insertNode(int val) {
    Node *temp = createNode(val);

    if (root == NULL) {
        root = temp;
        return;
    }

    Node *ptr = root;

    while (true) {
        if (val < ptr->data) {
            if (ptr->left == NULL) {
                ptr->left = temp;
                break;
            }
            ptr = ptr->left;
        }
        else {
            if (ptr->right == NULL) {
                ptr->right = temp;
                break;
            }
            ptr = ptr->right;
        }
    }
}

void inorder(Node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void preorder(Node *ptr) {
    if (ptr != NULL) {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(Node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

int main() {
    int ch, num;

    do {
        cout << "\n\n--- BST Menu ---";
        cout << "\n1. Insert Node";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number: ";
                cin >> num;
                insertNode(num);
                break;

            case 2:
                cout << "Inorder: ";
                inorder(root);
                break;

            case 3:
                cout << "Preorder: ";
                preorder(root);
                break;

            case 4:
                cout << "Postorder: ";
                postorder(root);
                break;

            case 5:
                cout << "Program terminated.";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (ch != 5);

    return 0;
}
