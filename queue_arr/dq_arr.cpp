#include <iostream>

using namespace std;

#define MAX_SIZE 100

class Deque {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
public:
    Deque() {
        front = -1;
        rear = 0;
    }
    bool isEmpty() {
        return (front == -1 && rear == 0);
    }
    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1);
    }
    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
            front = MAX_SIZE - 1;
        else
            front--;
        arr[front] = element;
    }
    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX_SIZE - 1)
            rear = 0;
        else
            rear++;
        arr[rear] = element;
    }
    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return -1;
        }
        int element = arr[front];
        if (front == rear) {
            front = -1;
            rear = 0;
        }
        else if (front == MAX_SIZE - 1)
            front = 0;
        else
            front++;
        return element;
    }
    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return -1;
        }
        int element = arr[rear];
        if (front == rear) {
            front = -1;
            rear = 0;
        }
        else if (rear == 0)
            rear = MAX_SIZE - 1;
        else
            rear--;
        return element;
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return -1;
        }
        return arr[front];
    }
    int getRear() {
        if (isEmpty() || rear < 0) {
            cout << "Deque Underflow\n";
            return -1;
        }
        return arr[rear];
    }
    void display() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
    int countNodes() {
        if (isEmpty())
            return 0;
        int i = front;
        int count = 0;
        while (i != rear) {
            count++;
            i = (i + 1) % MAX_SIZE;
        }
        return count + 1;
    }
};

int main() {
    Deque dq;
    dq.insertFront(5);
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.display();
    cout << "Front element: " << dq.getFront() << endl;
    return 0;
}