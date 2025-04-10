#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        int maxLen = 1;
        
        for(int i =0; i<n; i++){
            int len = 1;
            for(int j = i+1; j<n; j++){
                if(nums[j] > nums[j-1]){
                    len++;
                }
                else{
                    break;
                }
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
*/

class Solution{
    public:
    int findLengthOfLCIS(vector<int>&nums){
        int n = nums.size();
        if(n ==0) return 0;

        int count =1;
        int ans =1;

        for(int i =0;i<n;i++){
            if(nums[i] > nums[i-1]){
                count++;
                ans = max(ans, count);
            }
            else{
                count =1;
            }
        }
        return ans;
    }
};

int main() {
    
    Solution sol;

    vector<int>nums={1,2,3,6,5};

    int ans = sol.findLengthOfLCIS(nums);

    cout<<"ans is "<<ans<<endl;

    return 0;
}