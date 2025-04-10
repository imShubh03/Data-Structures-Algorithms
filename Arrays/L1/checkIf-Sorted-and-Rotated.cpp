#include<bits/stdc++.h>
using namespace std;

/* TC:O(n*n) SC:O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();

        vector<int>sorted = nums;

        sort(sorted.begin(), sorted.end());

        for(int r= 0; r <n; r++){
            bool isSorted = true;
            for(int i =0; i<n; i++){

                if(sorted[i] != nums[(i+r) % n]){
                    isSorted = false;
                    break;
                }
            }

            if(isSorted) {
                return true;
            }
        }

        return false;
    }
};
*/

// TC:O(n) SC:O(1)
class Solution {
public:
    bool check(int arr[], int n) {
        int cnt = 0; // Count for unsorted adjacent pairs

        // Check for decreasing adjacent pairs in the array
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) cnt++;
        }

        // Check if the last element is greater than the first (cyclic property)
        if (arr[n - 1] > arr[0]) cnt++;

        // Return true if there is at most one unsorted pair
        return cnt <= 1;
    }
};

int main() {
    Solution sol;
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Output the result: YES if it can be sorted by circular rotation, NO otherwise
    cout << (sol.check(arr, n) ? "YES" : "NO") << endl;

    return 0;
}
