#include <iostream>
using namespace std;

// A utility function to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp
void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// A function to do radix sort of arr[]
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

// A utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver function
int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the radix sort function
    radixSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}
