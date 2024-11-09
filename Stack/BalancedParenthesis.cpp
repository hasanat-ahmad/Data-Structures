#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expression){
    stack<char> mystack;

    for (char ch : expression){
        if (ch == '[' || ch == '{' || ch == '('){
            mystack.push(ch);
        }
        else if (ch == ']'){
            if ('[' == mystack.top()){
                mystack.pop();
            }
            else{
                return false;
            }
        }
        else if (ch == '}'){
            if ('{' == mystack.top()){
                mystack.pop();
            }
            else{
                return false;
            }
            
        }
        else if (ch == ')'){
            if ('(' == mystack.top()){
                mystack.pop();
            }
            else{
                return false;
            }
            
        }
    }
    return true;
}

int main(){
    string expression = "([)]{}";
    if (isBalanced(expression)){
        cout << "Balanced" << endl;
    }
    else{
        cout << "Unbalanced" << endl;
    }
}