#include <iostream>
using namespace std;

// TC:O(2^n)
int fibonacci(int n) {
    // Base case: fibonacci(0) = 0 and fibonacci(1) = 1
    if (n <= 1) return n;
    // Recursive call for fibonacci(n)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    
    int result = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is: " << result << endl;
    
    return 0;
}
