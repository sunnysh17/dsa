#include <iostream>
#include <string>

using namespace std;

const int MAX_STACK_SIZE = 100;

// Array-based stack class
class Stack {
private:
    int top;
    char data[MAX_STACK_SIZE];

public:
    Stack() {
        top = -1;
    }

    void push(char value) {
        if (top == MAX_STACK_SIZE - 1) {
            cerr << "Stack overflow!" << endl;
            exit(1);
        }
        top++;
        data[top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cerr << "Stack underflow!" << endl;
            exit(1);
        }
        char value = data[top];
        top--;
        return value;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            exit(1);
        }
        return data[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to check if a given character is an opening bracket
bool isOpeningBracket(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

// Function to check if a given character is a closing bracket
bool isClosingBracket(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

// Function to check if a pair of brackets matches
bool bracketsMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Function to check if an infix expression is balanced by brackets
bool isBalanced(string infix) {
    Stack st;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isOpeningBracket(ch)) {
            st.push(ch);
        }
        else if (isClosingBracket(ch)) {
            if (st.isEmpty()) {
                return false;
            }
            char open = st.pop();
            if (!bracketsMatch(open, ch)) {
                return false;
            }
        }
    }

    return st.isEmpty();
}

int main() {
    string infix = "(2+3)*5)/2";
    bool balanced = isBalanced(infix);
    if (balanced) {
        cout << "The expression is balanced." << endl;
    }
    else {
        cout << "The expression is not balanced." << endl;
    }

    return 0;
}
