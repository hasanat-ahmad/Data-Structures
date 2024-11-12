#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

struct Node *root;

Node *insert(struct Node *node, int data)
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

void print(Node *node)
{
    if (!node)
    {
        return;
    }

    print(node->left);
    cout << node->data << " ";
    print(node->right);
}

int main()
{
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 80);
    root = insert(root, 2);
    root = insert(root, 1);

    print(root);
    return 0;
}