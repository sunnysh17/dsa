#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter number of elements in an array: "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter elements in an array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                //swap(arr[j],arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout<<"Bubble Sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}