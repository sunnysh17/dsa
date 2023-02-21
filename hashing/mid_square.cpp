#include <iostream>
#include <cmath>
using namespace std;

const int TABLE_SIZE = 10;  // size of the hash table

// Function to compute the mid-square hash of a given key
int midSquareHash(int key, int tableSize)
{
    // compute the square of the key
    int squaredKey = key * key; // 10*10 = 100

    // determine the number of digits in the squared key
    int numDigits = (int)log10(squaredKey) + 1; 

    // if the squared key has an odd number of digits,
    // we need to add a leading zero to make it even
    if (numDigits % 2 != 0) {
        squaredKey *= 10;
        numDigits++;
    }

    // extract the middle portion of the squared key
    // as the hash value
    int halfNumDigits = numDigits / 2;
    int hashValue = squaredKey / (int)pow(10, halfNumDigits);
    hashValue %= tableSize;  

    return hashValue;
}

// Function to search for a given key in the hash table
int search(int key, int table[])
{
    // compute the hash value for the key
    int hashValue = midSquareHash(key, TABLE_SIZE);

    // search for the key at the computed hash value
    if (table[hashValue] == key) {
        return hashValue; //returns index
    }
    else {
        return -1;
    }
}

int main()
{
    int table[TABLE_SIZE] = {0};  // initialize the hash table to all zeros

    // insert some keys into the hash table
    int keys,no;
    cout<<"Enter no of values to be inserted in hash table: "<<endl;
    cin>>no;
     cout<<"Enter Keys: "<<endl;
    for(int i=0;i<no;i++)
    {   
        cin>>keys;
        table[midSquareHash(keys, TABLE_SIZE)] = keys;
    }
    

    // get the key to search for from the user
    int key;
    std::cout << "Enter a key to search for: ";
    std::cin >> key;

    // search for the key in the hash table
    int index = search(key, table);
    if (index != -1) {
        std::cout << "Key found at index " << index << " in the hash table" << std::endl;
    }
    else {
        std::cout << "Key not found in the hash table" << std::endl;
    }

    return 0;
}
