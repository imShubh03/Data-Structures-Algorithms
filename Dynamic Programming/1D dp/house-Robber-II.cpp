#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++) {
        int pick = nums[i];
        if (i > 1) {
            pick += prev2;
        }
        int notpick = prev1;

        int curr = max(pick, notpick);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++) {
        if (i != 0) temp1.push_back(nums[i]);
        if (i != n - 1) temp2.push_back(nums[i]);
    }

    return max(solve(temp1), solve(temp2));
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = rob(nums);
    cout << result << endl;

    return 0;
}
