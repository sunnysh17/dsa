
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail,Node* &head,int position, int d){

    if(position == 1){
        insertAtHead(head,d);
        return;
    }
   
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}

void deleteNode(Node* &head, int position){

    //delete first or start node
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        //free memory
        temp->next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node ot last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


void printNodes(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ">";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    int flag = 1, choice, value,position;
    while (flag == 1)
    {
        cout << "\n 1.insertHead 2.insertTail 3.insertAtPosotion 4.PrintNodes 5.DeleteNodes 6.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to be inserted at head: " << endl;
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter value to be inserted at tail: " << endl;
            cin >> value;
            insertAtTail(tail, value);
            break;


        case 3:
            cout << "Enter Position: " << endl;
            cin>>position;
            cout<<"Enter value to be inserted at specific position: "<<endl;
            cin>>value;
            insertAtPosition(tail,head,position,value);
            break;

        case 4:
            cout << "Display Linked List " << endl;
            printNodes(head);
            break;

        case 5:
            cout << "Enter Position you want to delete: " << endl;
            cin>>position;
            deleteNode(head,position);
            break;

        case 6:
            flag = 0;
            break;
        }
    }

    return 0;
}