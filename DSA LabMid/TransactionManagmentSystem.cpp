#include <iostream>
using namespace std;

struct TransactionNode
{
    int transactionID;
    float amount;
    TransactionNode *left;
    TransactionNode *right;

    TransactionNode(int id, float amount) : transactionID(id), amount(amount), left(NULL), right(NULL) {}
};

TransactionNode *InsertTransaction(TransactionNode *root, int transactionID, float amount)
{
    if (root == NULL)
    {
        return new TransactionNode(transactionID, amount);
    }
    if (transactionID < root->transactionID)
    {
        root->left = InsertTransaction(root->left, transactionID, amount);
    }
    else if (transactionID > root->transactionID)
    {
        root->right = InsertTransaction(root->right, transactionID, amount);
    }
    return root;
}

TransactionNode *Identify_largest_transaction(TransactionNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    TransactionNode *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

void Generate_a_report(TransactionNode *root)
{
    if (root == nullptr)
        return;
    Generate_a_report(root->left);
    cout << "Transaction ID: " << root->transactionID << " Amount: " << root->amount << endl;
    Generate_a_report(root->right);
}

bool Quicklyverifytransaction(TransactionNode *root, int transactionID)
{
    if (root == NULL)
    {
        return false;
    }
    if (transactionID == root->transactionID)
    {
        return true;
    }
    else if (transactionID < root->transactionID)
    {
        return Quicklyverifytransaction(root->left, transactionID);
    }
    else
    {
        return Quicklyverifytransaction(root->right, transactionID);
    }
}

int main()
{
    TransactionNode *root = NULL;

    root = InsertTransaction(root, 1001, 250.75);
    root = InsertTransaction(root, 1002, 120.50);
    root = InsertTransaction(root, 1003, 450.90);
    root = InsertTransaction(root, 1004, 300.25);

    TransactionNode *largest = Identify_largest_transaction(root);
    if (largest != nullptr)
    {
        cout << "Largest Transaction: ID = " << largest->transactionID << " Amount = " << largest->amount << endl;
    }

    cout << "Report is given below" << endl;
    Generate_a_report(root);

    int transactionID;
    cout << "Enter Transaction ID to verify: ";
    cin >> transactionID;
    if (Quicklyverifytransaction(root, transactionID))
    {
        cout << transactionID << " found.\n";
    }
    else
    {
        cout << transactionID << " not found.\n";
    }

    return 0;
}
