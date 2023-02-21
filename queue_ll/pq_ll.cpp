#include <iostream>

using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;
};

class PriorityQueue
{
private:
    Node *head;

public:
    PriorityQueue()
    {
        head = NULL;
    }

    void enqueue(int data, int priority)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->priority = priority;

        if (head == NULL || priority < head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->priority <= priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void peek()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << head->data << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int countNodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    PriorityQueue pq;

    int flag = 1, choice, value,priority;
    while (flag == 1)
    {
        cout << "\n 1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: " << endl;
            cin >> value;
            cout << "Enter priority: " << endl;
            cin >> priority;
            pq.enqueue(value,priority);
            break;

        case 2:
            pq.dequeue();
            break;

        case 3:
            pq.peek();
            break;

        case 4:
            pq.display();
            break;

        case 5:
            flag = 0;
            break;
        }
    }

    return 0;
}
