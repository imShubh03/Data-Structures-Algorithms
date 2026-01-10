#include<bits/stdc++.h>
using namespace std;
/*
// brute force (sorting)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1; // Initialize ans to handle cases where no duplicate is found
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) { 
                ans = nums[i];
                break; // Break loop as soon as duplicate is found
            }
        }
        return ans;
    }
};
// TC = O(nlogn + n)
// SC : O(1)
*/

/*
// freq count method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>count(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int ind =-1;
        for(int j=0;j<count.size();j++){
            if(count[j] >1){
                ind = j;
                break;
            }
        }
        return ind;
    }
};

// TC = O(n)
// SC = O(n)
*/


//floyds cycle detection method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize pointers directly with indices for faster convergence
        int slow = nums[0];
        int fast = nums[0]; 

        // Iterate until a cycle is found
        do {
            slow = nums[slow];  // Move slow pointer one step at a time
            fast = nums[nums[fast]];  // Move fast pointer two steps at a time
        } while (slow != fast);

        // Reset fast pointer to the beginning and iterate until cycle entrance
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;  // Return the duplicate number
    }
};
// TC : O(n)
// SC: O(1)



int main() {
    // Example usage
    vector<int> nums = {1, 3, 4, 2, 2}; // Example vector with a duplicate
    Solution sol;
    int duplicate = sol.findDuplicate(nums);
    if (duplicate != -1) {
        cout << "The duplicate element in the vector is: " << duplicate << endl;
    } else {
        cout << "No duplicate element found in the vector." << endl;
    }

    return 0;
}
