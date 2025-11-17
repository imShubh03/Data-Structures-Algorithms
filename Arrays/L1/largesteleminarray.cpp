#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    
    for(int i = n-2; i>=0;i--){
        if(arr[i] != arr[n-1]){
            return arr[i];
        }
    }
    
    return -1;
}

/*
int largestElement(vector<int> &arr, int n) {
    int largest = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}
*/

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int largest = largestElement(numbers, n);
    cout << "The largest element in the array is: " << largest << endl;

    return 0;
}
