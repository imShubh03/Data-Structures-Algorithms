#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& subSet, vector<vector<int>>& res) {
        if(k == 0 && n == 0) {
            res.push_back(subSet);
            return;
        }
        if(k == 0 || n < 0) return;

        for(int i = start; i <= 9; i++) {
            subSet.push_back(i);
            backtrack(i + 1, k - 1, n - i, subSet, res);
            subSet.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> subSet;
        backtrack(1, k, n, subSet, res);
        return res;
    }
};

int main() {
    int k, n;
    cin >> k >> n;

    Solution sol;
    vector<vector<int>> result = sol.combinationSum3(k, n);

    for(auto& subset : result) {
        cout << "[";
        for(int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if(i < subset.size() - 1) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
