#include <iostream>
#include <cstring>

using namespace std;

class Node
{
public:
    Node *head;
    Node *next;
    int size, data;

    Node(int d)
    {
        int size = 0;
        data = d;
        Node *head = NULL;
    }
};

void push(Node *&head, int element)
{
    int size = 0;
    Node *temp = new Node(element);
    temp->next = head;
    size++;
    head = temp;
}

int pop(Node *&head)
{
    int size=0;
    if (head == NULL)
    {
        cout << "Stack underflow" << endl;
    }

    int res = head->data;
    head = head->next;
    size--;
    return res;
}

void display(Node* head) {
        if(head == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

void peek(Node* &head){
   Node* temp = head;
   if(temp!=NULL){
        cout<<temp->data<<endl;
   }

}

int main()
{

    Node* node1 = new Node(10);
    Node* head = node1;

    push(head,2);
    push(head,3);
    push(head,4);
    display(head);
    pop(head);
    display(head);
    peek(head);

    return 0;
}