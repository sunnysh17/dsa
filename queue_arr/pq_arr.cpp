#include <iostream>
using namespace std;

const int MAX_SIZE = 100;  // Maximum size of the priority queue

struct PriorityQueue {
    int data[MAX_SIZE];
    int front, rear;
};

// Initialize a new priority queue
void initQueue(PriorityQueue &q) {
    q.front = -1;
    q.rear = -1;
}

// Check if the priority queue is empty
bool isEmpty(PriorityQueue &q) {
    return (q.front == -1 && q.rear == -1);
}

// Check if the priority queue is full
bool isFull(PriorityQueue &q) {
    return (q.rear == MAX_SIZE - 1);
}

// Add an element to the priority queue
void enqueue(PriorityQueue &q, int value) {
    if (isFull(q)) {
        cout << "Queue is full." << endl;
        return;
    }
    if (isEmpty(q)) {
        q.front = q.rear = 0;
        q.data[0] = value;
        return;
    }
    int i;
    for (i = q.rear; i >= 0; i--) {
        if (value > q.data[i]) {
            q.data[i + 1] = q.data[i];
        } else {
            break;
        }
    }
    q.data[i + 1] = value;
    q.rear++;
}

// Remove an element from the priority queue
void dequeue(PriorityQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty." << endl;
        return;
    }
    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front++;
    }
}

// Peek at the front element of the priority queue
int peek(PriorityQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return q.data[q.front];
}

// Display the elements of the priority queue
void display(PriorityQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty." << endl;
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.data[i] << " ";
    }
    cout << endl;
}

// Count the number of nodes in the priority queue
int countNodes(PriorityQueue &q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q.rear - q.front + 1;
}

int main() {
    PriorityQueue q;
    initQueue(q);

    enqueue(q, 10);
    enqueue(q, 5);
    enqueue(q, 20);
    enqueue(q, 15);

    display(q);  // Output: 20 15 10 5
    cout << "Front element: " << peek(q) << endl;  // Output: Front element: 20
    dequeue(q);
    display(q);  // Output: 15 10 5
    cout << "Number of nodes: " << countNodes(q) << endl;  // Output: Number of nodes: 3

    return 0;
}
