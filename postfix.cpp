#include <iostream>
#include <cstring>

using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* expression) {
    char stack[100]; // Array for stack
    int top = -1; // Initialize top of stack to -1
    int length = strlen(expression); // Get length of expression

    for(int i = 0; i < length; i++) {
        // If the character is an operand, add it to the postfix expression
        if(isalnum(expression[i])) {
            cout << expression[i];
        }
        // If the character is a left parenthesis, push it onto the stack
        else if(expression[i] == '(') {
            stack[++top] = expression[i];
        }
        // If the character is a right parenthesis, pop from the stack and add to postfix expression until a left parenthesis is encountered
        else if(expression[i] == ')') {
            while(top != -1 && stack[top] != '(') {
                cout << stack[top--];
            }
            top--;
        }
        // If the character is an operator, pop from the stack and add to postfix expression until a lower precedence operator is encountered
        else {
            while(top != -1 && precedence(expression[i]) <= precedence(stack[top])) {
                cout << stack[top--];
            }
            stack[++top] = expression[i];
        }
    }
    // Pop any remaining operators from the stack and add to postfix expression
    while(top != -1) {
        cout << stack[top--];
    }
}

int main() {
    char expression[100];
    cout << "Enter infix expression: ";
    cin.getline(expression, 100);
    cout << "Postfix expression: ";
    infixToPostfix(expression);
    return 0;
}
