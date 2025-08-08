#include<bits/stdc++.h>
using namespace std;

/*
// TC: O(2^n * n), SC: O(2^n * n)
class Solution {
public:
    void generate(int index, vector<int>& arr, int n, vector<int>& temp, vector<vector<int>>& powerset) {
        if(index == n) {
            powerset.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(arr[index]);
        generate(index + 1, arr, n, temp, powerset);

        // Exclude current element
        temp.pop_back();
        generate(index + 1, arr, n, temp, powerset);
    }

    vector<vector<int>> getPowerset(vector<int>& arr, int n) {
        vector<vector<int>> powerset;
        vector<int> temp;
        generate(0, arr, n, temp, powerset);
        return powerset;
    }
};
*/
//TC O(2^n) +O(2^n logn)   SC:O(2^n) + O(n)
class Solution {
    public:
    // Function to find all subset sums
    void findSum(vector<int> arr, int n, int index, int sum, vector<int>& subsetSum) {
        // Base case: if we reach the end of the array
        if(index == n) {
            subsetSum.push_back(sum);
            return;
        }
        
        // Pick the current element
        findSum(arr, n, index + 1, sum + arr[index], subsetSum);
        
        // Do not pick the current element
        findSum(arr, n, index + 1, sum, subsetSum);
    }

    // Function to get all subset sums
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> subsetSum;
        findSum(arr, n, 0, 0, subsetSum);
        sort(subsetSum.begin(), subsetSum.end());
        return subsetSum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    vector<int> result = sol.subsetSums(arr, n);

    // Print the result
    cout << "Subset sums are: ";
    for(int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
