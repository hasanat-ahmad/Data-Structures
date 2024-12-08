#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root;
Node *result;

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        Node *newNode = new Node();
        newNode->data = data;
        return newNode;
    }

    if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        node->left = insert(node->left, data);
    }
    return node;
}

Node *searchElement(Node *node, int key)
{
    if (node == NULL || node->data == key)
    {
        return node;
    }
    if (key < node->data)
    {
        return searchElement(node->left, key);
    }
    else
    {
        return searchElement(node->right, key);
    }
}

void printNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printNode(node->left);
    cout << node->data << " ";
    printNode(node->right);
}

int main()
{
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 50);
    printNode(root);
    cout << endl;

    int target = 330;
    result = searchElement(root, target);

    if (result != NULL)
    {
        cout << "Found";
    }
    else
    {
        cout << "Not found";
    }
    return 0;
}