#include <bits/stdc++.h>

using namespace std;

/*  brute force, time:O(n^2)  space:O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            int flag = 0;  // Reset flag for each number
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return i;
            }
        }
        return -1;
    }
};
*/

/*  better time:O(n logn)  space:O(n)
class Solution {
    public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n;  
    }
};
*/


/*  better 2 : time:O(n)  space:O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int freqarr[n+1]={0};
        for (int i = 0; i < n; i++) {
            freqarr[nums[i]]++;
        }
        for(int i =1;i<=n;i++){
            if(freqarr[i] == 0){
                return i;
                break;
            }  
        }
        return -1;
    }
};
*/

//optimal time:O(n) space:O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n*(n+1)/2;
        int actualSum= 0;
        for(int i =0;i<n;i++){
            actualSum+=nums[i];
        }

        return expectedSum-actualSum;
    }
};


int main() {
    Solution solution;

    int n;
    cout << "Enter size of the array: " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Find the missing number
    int result = solution.missingNumber(nums);

    // Output the missing number
    cout << "The missing number is: " << result << endl;

    return 0;
}
