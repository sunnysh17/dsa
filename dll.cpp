#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};


void insertAtHead(Node* &head, int d){
      
      Node* temp = new Node(d);
      temp->next = head;
     
      head->prev = temp;
      head = temp;
}

void insertAtTail(Node* tail, int d){
    
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;

}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //insert At start
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int count = 1;

    //jis position main insert karna hai waha tak badho.
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
    temp->next->prev = nodeToInsert;

    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}


void printNodes(Node* head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"<>";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int getLength(Node* head){
    
    int length = 0;
    Node*temp = head;

    while(temp!=NULL){
        
        length++;
        temp = temp->next;
    }

    return length;
    cout<<endl;
    
}

void deleteNode(Node* &head, int position){

    //delete first or start node
    if(position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;  
        delete curr;
    }
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

   int flag = 1, choice, value,position;
    while (flag == 1)
    {
        cout << "\n 1.insertHead 2.insertTail 3.insertAtPosition 4.PrintNodes 6.DeleteNodes 7.Exit\n";
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
            insertAtPosition(head,tail,position,value);
            break;

        case 4:
            cout << "Display Linked List " << endl;
            printNodes(head);
            break;

        case 5:
            cout << "Length of the Linked List " <<getLength(head)<<endl;
            break;

        case 6:
            cout << "Enter Position you want to delete: " << endl;
            cin>>position;
            deleteNode(head,position);
            break;

        case 7:
            flag = 0;
            break;
        }
    }

    return 0;
}