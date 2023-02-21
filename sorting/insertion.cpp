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

    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    cout<<"Insertion Sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;

}