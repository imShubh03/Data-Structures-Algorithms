#include <bits/stdc++.h>
using namespace std;

// TC : O(n 2^n) (loop*no of recur call)  SC:O(n)
class Solution {
public:
    void generate(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int index) {
        if(index == nums.size()) {
            if(!temp.empty()){ // this is only when [] not allowed
                res.push_back(temp);
            } 
            return;
        }

        temp.push_back(nums[index]);
        generate(res, temp, nums, index + 1);
        temp.pop_back();

        generate(res, temp, nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        generate(res, temp, nums, 0);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> res = obj.subsets(nums);

    for(auto &subset : res) {
        for(int val : subset) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
