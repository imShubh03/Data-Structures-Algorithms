#include<bits/stdc++.h>
using namespace std;

vector<int> findTriplet(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> temp;

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            if (arr[i] + arr[left] > arr[right]) {
                temp.push_back(arr[i]);
                temp.push_back(arr[left]);
                temp.push_back(arr[right]);
                return temp; // Found a triplet, return it
            } else {
                // Move pointers
                left++;
                right--;
            }
        }
    }
    // If no such triplet exists
    return temp;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
    
    vector<int> result = findTriplet(arr);
    
    if (result.empty()) {
        cout << "No such triplet found." << endl;
    } else {
        cout << "Triplet: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
