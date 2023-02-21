#include <iostream>

using namespace std;

int main() {

    int n, gap;
    cout << "Enter number of elements in an array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter elements in an array: " << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Corrected the loop condition
    for(gap = n/2; gap >= 1; gap /= 2) {
        for(int j = gap; j < n; j++) {
            for(int i = j - gap; i >= 0; i -= gap) {
                if(arr[i + gap] > arr[i]) {
                    break;
                } else {
                    swap(arr[i + gap], arr[i]);
                }
            }
        }
    }

    cout << "Shell Sort: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
