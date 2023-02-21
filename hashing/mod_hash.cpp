#include<iostream>
using namespace std;
void search(int a[], int size, int num){
    int pos = num%size;
    int count=0;
    int flag=0;
       
        while(a[pos]!=num){
            count++;
           
            if(a[pos]==a[size-1]){
                pos=0;
            }
            if(count==size){
                cout<<"not found";
                flag =1;
                break;
            }
            pos++;
           
        }
    if(flag==0){
    cout<<endl<<num<<" is found at index: "<<pos;}
}
int main()
{
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    int ar[n];
    int key,address;
    cout <<"enter the elements into the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        key=ar[i]; //The 'key' variable stores the current element of the input array.
        address = key % n; //The 'address' variable stores the hash code of the current element, which is computed by taking the remainder of the element after dividing it by the size of the array.
           while(arr[address] != -1 ) 
        {
            address ++;
            if (address == n) //'address' variable becomes equal to the size of the array
            address =0;
        }
            arr[address]= key;
    }
   
    cout<<"after performing hashing array is:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
   
    int keytobefound;
    cout<<"\nEnter Key to be Found: "<<endl;
    cin>>keytobefound;
    search(arr,n,keytobefound);
    
   
    return 0;
}
