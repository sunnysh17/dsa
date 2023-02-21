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
            cerr << "Stack underflow!" << endl;
            exit(1);
        }
        return data[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to check if a given character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to convert an infix expression to postfix using a stack
string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); // Pop the opening parenthesis from the stack
        }
        else if (isOperator(ch)) {
            while (!st.isEmpty() && getPrecedence(ch) <= getPrecedence(st.peek())) {
                postfix += st.pop();
            }
            st.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression using a stack
int evaluatePostfix(string postfix) {
    Stack st;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            st.push(ch - '0'); // Convert character to integer and push onto stack
        }
        else if (isOperator(ch)) {
            int operand2 = st.pop();
            int operand1 = st.pop();

            int result;
            if (ch == '+') {
                result = operand1 + operand2;
            }
            else if (ch == '-') {
                result = operand1 - operand2;
            }
            else if (ch == '*') {
                result = operand1 * operand2;
            }
            else {
                result = operand1 / operand2;
            }

            st.push(result);
        }
    }

    return st.pop();
}

int main() 
{
    string infix = "2+3";
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression:"<<postfix<<endl;

    int result = evaluatePostfix(postfix);
    cout << "postfix evaluation: " << result << endl;
    return 0;

}
