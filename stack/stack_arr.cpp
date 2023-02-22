#include <iostream>
using namespace std;
#define SIZE 6
int A[SIZE];
int top = -1;

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(int element)
{
    if (top == SIZE - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        A[top] = element;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        top--;
       // cout<<"Popped Element is: "<<A[top--]<<endl;
    }
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Top element is: " << A[top] << endl;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << "Stack Elements: " << A[i] << " " << endl;
        }
    }
}

int main()
{

    int choice, flag = 1, value;
    while (flag == 1)
    {
        cout << "\n1.Push 2.Pop 3.Peek 4.isEmpty? 5.Display\n"<< endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element to be pushed: " << endl;
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            cout << "Is Stack Empty?: " << endl;
            isEmpty();
            break;

        case 5:
            display();
            break;

        case 6:
            flag = 0;
            break;
        }
    }

    return 0;
}