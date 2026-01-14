#include <bits/stdc++.h>
using namespace std;

/* brute : time:O(nlogn)+O(n^2) space:O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Skip already merged intervals
            // [1,3] [2, 4] [2, 6]
            //ans = [1, 6]     - [4, 5]   6 > 5 skip
            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }

            // Merge overlapping intervals
            [1, 3] [2, 6]     
            end = 3
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                } else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};
*/

// optimised time:O(nlogn)+O(n) space:O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        if(n==0) return ans;

        sort(intervals.begin(), intervals.end());
        vector<int>tempInt= intervals[0];

        for(auto it : intervals){
            if(it[0]<= tempInt[1]){
                tempInt[1]= max(it[1], tempInt[1]);
            }
            else{
                ans.push_back(tempInt);
                tempInt = it;
            }
        }
        ans.push_back(tempInt);

        return ans;
    }
};


int main() {
    Solution obj;

    // Test case
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = obj.merge(intervals);

    // Print merged intervals
    cout << "Merged Intervals: " << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
