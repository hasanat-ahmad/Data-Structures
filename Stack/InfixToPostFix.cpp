#include <iostream>
#include <stack>
using namespace std;

int precedence(char operand) {
    if (operand == '+' || operand == '-')
        return 1;
    if (operand == '*' || operand == '/')
        return 2;
    if (operand == '^')
        return 3;
    return 0;
}

string infixToPostFix(string s) {
    stack<char> myStack;
    string answer;
    for (char ch : s) {
        // If the character is an operand (letter), add it to the answer
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            answer += ch;
        }
        // If the character is an opening parenthesis, push it to the stack
        else if (ch == '(') {
            myStack.push(ch);
        }
        // If the character is a closing parenthesis
        else if (ch == ')') {
            while (!myStack.empty() && myStack.top() != '(') {
                answer += myStack.top();
                myStack.pop();
            }
            if (!myStack.empty()) {
                myStack.pop(); // Pop the opening parenthesis
            }
        }
        // If the character is an operator
        else {
            while (!myStack.empty() && precedence(myStack.top()) >= precedence(ch)) {
                answer += myStack.top();
                myStack.pop();
            }
            myStack.push(ch); // Push the current operator
        }
    }

    // Pop all remaining operators in the stack
    while (!myStack.empty()) {
        answer += myStack.top();
        myStack.pop();
    }

    return answer;
}

int main() {
    string infix = "A+B";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostFix(infix) << endl;
    return 0;
}
