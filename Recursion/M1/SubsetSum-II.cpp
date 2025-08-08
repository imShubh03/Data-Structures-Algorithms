#include<bits/stdc++.h>
using namespace std;

/* TC : O(2^n * n log n)  SC:O(n * 2^n)(store) + O(n)(rec sta)
class Solution {
public:
    void generate(int index, vector<int>& nums, vector<int>& temp, set<vector<int>>& result) {
        if(index == nums.size()) {
            vector<int> subset = temp;
            sort(subset.begin(), subset.end()); 
            result.insert(subset);
            return;
        }

        temp.push_back(nums[index]);
        generate(index + 1, nums, temp, result);

        temp.pop_back();
        generate(index + 1, nums, temp, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> temp;
        generate(0, nums, temp, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
};
*/

class Solution {
public:
    void solve(vector<int>&nums, int ind, vector<int>&temp, vector<vector<int>>&res){
        //add the empty ds 
        res.push_back(temp);

        for(int i = ind; i<nums.size(); i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            solve(nums, i + 1, temp, res);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(nums.begin(), nums.end());

        solve(nums, 0, temp, res);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> ans = subsetsWithDup(nums);

    for(auto subset : ans) {
        cout << "[";
        for(int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if(i < subset.size() - 1) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
