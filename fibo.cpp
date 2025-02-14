#include <iostream>
using namespace std;

class Fibonacci {
public:
    int n;
    
    // Constructor to generate Fibonacci series
    Fibonacci(int num) {
        n = num;
        int first = 0, second = 1, next;
        
        cout << "Fibonacci Series: ";
        for (int i = 0; i < n; i++) {
            cout << first << " ";
            next = first + second;
            first = second;
            second = next;
        }
        cout << endl;
    }
};

int main() {
    int num;
    cout << "Enter the number of terms: ";
    cin >> num;
    
    Fibonacci fib(num);
    
    return 0;
}
