#include <iostream>
using namespace std;

// TC: O(n)  swaps are n/2   SC:O(n) recursive stack space
void reverseArray(int arr[], int start, int end) {
    if (start >= end) return;  // Base case: if start meets or exceeds end, return
    swap(arr[start], arr[end]);  // Swap the elements at start and end
    reverseArray(arr, start + 1, end - 1);  // Recursive call with updated indices
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverseArray(arr, 0, n - 1);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
