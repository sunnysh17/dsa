#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;

    if (rear == 0)
    {
        front = newnode;
        rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else if (front == rear)
    {
        front = rear = 0;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Front element: " << front->data << endl;
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
}

int main()
{

    int flag = 1, choice, value;
    while (flag == 1)
    {
        cout << "\n 1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter value: "<<endl;
            cin>>value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            flag = 0;
            break;
        
        }
    }
    return 0;
}
