#include<bits/stdc++.h>
using namespace std;

/* Brute TC:O(2^k * k logn) no if subset, ds into anot ds , set oper  SC: O(2^n * n) +O(n)+ O(n)
class Solution {
public:
    void generateAllSubsets(int i, vector<int>& arr, vector<int>& ds, set<vector<int>>& result, int target) {
        if (i == arr.size()) {
            int sum = accumulate(ds.begin(), ds.end(), 0);
            if (sum == target) {
                vector<int> temp = ds;
                sort(temp.begin(), temp.end());
                result.insert(temp);
            }
            return;
        }

        // include
        ds.push_back(arr[i]);
        generateAllSubsets(i + 1, arr, ds, result, target);
        ds.pop_back();

        // exclude
        generateAllSubsets(i + 1, arr, ds, result, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> resultSet;
        vector<int> ds;

        generateAllSubsets(0, candidates, ds, resultSet, target);

        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};
*/
class Solution {
public:
    void findcombi(vector<int>& arr, int target, int index, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) {
                continue;
            }
            if (arr[i] > target) {
                break;
            }

            ds.push_back(arr[i]);
            findcombi(arr, target - arr[i], i + 1, ans, ds);  // Note: index should be i + 1, not index + 1
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        findcombi(candidates, target, 0, ans, ds);
        return ans;  // Return the result from combinationSum2
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {10, 1, 2, 7, 6, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    // Print the result
    cout << "Combinations that sum up to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
