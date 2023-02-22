#include <iostream>
using namespace std;
#define SIZE 8
int arr[SIZE];
int front = 0;
int rear = 0;


void enqueue(int element){
    if(rear == SIZE){
        cout<<"Queue is full"<<endl;
    }
    else{
        arr[rear] = element;
        rear++;
    }
}


void dequeue(){
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        arr[front]=-1;
        front++;
        if(front==rear){
            front=0;
            rear=0;
        }
    }
}


void isEmpty(){
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
}

void qfront(){
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Front element in Queue is: "<<arr[front]<<endl;
    }
}

void display(){
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        for(int i=front;i<=rear-1;i++){
            cout<<arr[i]<<" "<<endl;
        }
    }
}



int main(){

    int choice,flag=1,value;
    while(flag==1){
        cout<<"\n 1.Enqueue 2.Dequeue 3.Display 4.Front\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter element to be pushed: "<<endl;
            cin>>value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            qfront();
            break;

        case 5:
            flag = 0;
            break;
        
        }
    }

    return 0;
}