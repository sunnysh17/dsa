#include <iostream>

using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front; // Pointer to front of queue
    Node *rear;  // Pointer to rear of queue
public:
    // Constructor to initialize front and rear to NULL
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Function to enqueue an element into the queue
    void enqueue(int element)
    {
        Node *temp = new Node();
        temp->data = element;
        temp->next = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    // Function to dequeue an element from the queue
    int dequeue()
    {
        if (front == NULL)
        {
            cout << "Error: Queue is empty\n";
            return -1; // Return -1 to indicate an error
        }
        int element = front->data;
        Node *temp = front;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
        delete temp;
        return element;
    }

    // Function to display the elements of the queue
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }
};

int main()
{
    Queue q;
    int flag = 1, choice, value;
    while (flag == 1)
    {
        cout << "\n 1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: " << endl;
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            flag = 0;
            break;
        }
    }

    return 0;
}
