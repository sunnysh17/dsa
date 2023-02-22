#include <iostream>
using namespace std;

int binarysearch(int arr[],int n, int key){
  int s = 0;
  int e = n;
  while(s<=e){
    int mid = (s+e)/2;

    if(arr[mid]==key){
      return mid;
    }
    else if(arr[mid]>key)
    {
      e = mid-1;
    }
    else
    {
      s =mid+1;       
    }
  }
  return -1;
}

int main(){

  int n;
  cout<<"Enter number of elements in an array: "<<endl;
  cin>>n;

  int arr[n];
  cout<<"Enter elements in an array: "<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int key;
  cout<<"Enter element to be found"<<endl;
  cin>>key;

  cout<<"element found at index: "<<endl;
  cout<<binarysearch(arr,n,key)<<endl;
  return 0;

}