#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void enqueueFront(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void enqueueBack(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeueFront() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        delete temp;
    }

    void dequeueBack() {
        if (tail == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        else {
            head = NULL;
        }
        delete temp;
    }

    void peekFront() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << head->data << endl;
    }

    void peekBack() {
        if (tail == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Back element is: " << tail->data << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dq;

    dq.enqueueFront(10);
    dq.enqueueFront(20);
    dq.enqueueBack(30);
    dq.enqueueBack(40);

    dq.display();

    dq.dequeueFront();

    dq.display();

    dq.peekFront();
    dq.peekBack();

    cout << "Number of nodes: " << dq.countNodes() << endl;

    return 0;
}
