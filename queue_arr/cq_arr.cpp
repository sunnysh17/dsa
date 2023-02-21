#include<iostream>
using namespace std;
#define SIZE 6
int arr[SIZE];
int front=-1;
int rear=-1;

void enqueue(int element){
    if((front==0 && rear==SIZE-1) || rear == (front-1)%(SIZE-1)){
        cout<<"Queue is full"<<endl;
    }
    else if(front == -1){
        front=rear=0;
    }
    else if(front!=0 && rear==SIZE-1){
        rear=0;
    }
    else{
        rear++;
    }
    arr[rear] = element;
} 

void dequeue(){
    if(front == -1){
        cout<<"Queue is Empty"<<endl;
    }
    
    int ans = arr[front];
    arr[front] = -1;
    
    if(front == rear){
        front=rear=-1;
    }
    else if(front = SIZE-1){
        front=0;
    }
    else{
        front++;
    }
    
}

void display(){
    int i = front;
    if(front == -1 && rear == -1){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        while(i!=rear){
            cout<<arr[i]<<" "<<endl;
            i = (i+1)%SIZE;
        }
        cout<<arr[rear]<<" "<<endl;
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

        case 5:
            flag = 0;
            break;
        
        }
    }

    return 0;
}

