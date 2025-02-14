#include <iostream>
#include <stack>
using namespace std;

// Function to reverse an array using a stack
void reverseArray(int arr[], int n) {
    stack<int> s;
    
    // Push all elements into the stack
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }
    
    // Pop all elements from the stack and put them back in the array
    for (int i = 0; i < n; i++) {
        arr[i] = s.top();
        s.pop();
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    reverseArray(arr, n);
    
    cout << "Reversed array: ";
    printArray(arr, n);
    
    return 0;
}
