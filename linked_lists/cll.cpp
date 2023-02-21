#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertNode(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp; // circular nature
    }
    else
    {

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void printNodes(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout<<endl;
}

int main()
{


    Node* tail = NULL;
    insertNode(tail, 5, 3);
    printNodes(tail);

    insertNode(tail, 3, 5);
    printNodes(tail);

    insertNode(tail, 5, 7);
    printNodes(tail);

    insertNode(tail, 7, 9);
    printNodes(tail);

    insertNode(tail, 5, 6);
    printNodes(tail);
    
    insertNode(tail, 9, 10);
    printNodes(tail);

    return 0;
}