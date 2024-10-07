#include <iostream>

using namespace std;

// Node structure to represent non-zero elements in the sparse matrix
struct Node {
    int row;      // Row index (departure airport)
    int col;      // Column index (arrival airport)
    int value;    // Value (number of flights)
    Node* next;   // Pointer to the next node

    // Constructor for node
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// Class to represent a sparse matrix using a linked list
class SparseMatrix {
private:
    Node* head;   // Head of the linked list

public:
    // Constructor
    SparseMatrix() : head(nullptr) {}

    // Insert a non-zero value into the matrix
    void insert(int row, int col, int value) {
        if (value == 0) return;  // We only store non-zero values

        Node* newNode = new Node(row, col, value);
        newNode->next = head;
        head = newNode;
    }

    // Function to transpose the sparse matrix
    SparseMatrix transpose() {
        SparseMatrix transposed;
        Node* current = head;

        // Traverse through the list and swap row and column for each node
        while (current != nullptr) {
            transposed.insert(current->col, current->row, current->value);
            current = current->next;
        }
        return transposed;
    }

    // Function to add another sparse matrix to this matrix
    void add(SparseMatrix& other) {
        Node* current = other.head;

        // Traverse the other matrix and add values to the current matrix
        while (current != nullptr) {
            addValue(current->row, current->col, current->value);
            current = current->next;
        }
    }

    // Function to multiply two matrices
    SparseMatrix multiply(SparseMatrix& other, int size) {
        SparseMatrix result;

        Node* currentA = head;
        while (currentA != nullptr) {
            Node* currentB = other.head;

            // For each element in matrix A, find matching column in B and multiply
            while (currentB != nullptr) {
                if (currentA->col == currentB->row) {
                    int newVal = currentA->value * currentB->value;
                    result.addValue(currentA->row, currentB->col, newVal);
                }
                currentB = currentB->next;
            }
            currentA = currentA->next;
        }

        return result;
    }

    // Function to print the matrix
    void print() {
        Node* current = head;
        cout << "Sparse Matrix (row, column, value):" << endl;
        while (current != nullptr) {
            cout << "(" << current->row << ", " << current->col << ", " << current->value << ")" << endl;
            current = current->next;
        }
    }

private:
    // Helper function to add value to the matrix (used in addition and multiplication)
    void addValue(int row, int col, int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->row == row && current->col == col) {
                current->value += value;
                return;
            }
            current = current->next;
        }

        // If no matching node found, insert a new one
        insert(row, col, value);
    }
};

// Main function for testing
int main() {
    SparseMatrix flights;

    // Insert some flight data
    flights.insert(0, 2, 3);
    flights.insert(1, 3, 4);
    flights.insert(3, 1, 5);

    cout << "Original matrix:" << endl;
    flights.print();

    // Transpose the matrix
    SparseMatrix transposed = flights.transpose();
    cout << "Transposed matrix:" << endl;
    transposed.print();

    // Add two matrices (for demonstration, we add the matrix to itself)
    flights.add(transposed);
    cout << "After adding transposed matrix:" << endl;
    flights.print();

    // Multiply matrices (with itself for demonstration)
    SparseMatrix multiplied = flights.multiply(transposed, 4);
    cout << "Multiplied matrix:" << endl;
    multiplied.print();

    return 0;
}
