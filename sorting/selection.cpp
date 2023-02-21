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

    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }

    cout<<"Selection Sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}