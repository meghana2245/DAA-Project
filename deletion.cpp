#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

Node* findMin(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int value) {
    if(root == NULL)
        return root;

    if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else {

        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        else if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, value, del;

    cout << "Enter number of values to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for(int i = 0; i < n; i++) {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "\nInorder before deletion: ";
    inorder(root);

    cout << "\n\nEnter value to delete: ";
    cin >> del;

    root = deleteNode(root, del);


    cout << "\nInorder after deletion: ";
    inorder(root);

    return 0;
}