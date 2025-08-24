#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int index, long long curVal, long long preVal, string exp, string &num, int target, vector<string>& ans) {
        // base case: reached end of string
        if (index == num.size()) {
            if (curVal == target) ans.push_back(exp);
            return;
        }

        // try all possible partitions
        for (int i = index; i < num.size(); i++) {
            // skip numbers with leading zero
            if (i > index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long long val = stoll(part);

            if (index == 0) {
                // first number (no operator before it)
                dfs(i + 1, val, val, part, num, target, ans);
            } else {
                // addition
                dfs(i + 1, curVal + val, val, exp + "+" + part, num, target, ans);
                // subtraction
                dfs(i + 1, curVal - val, -val, exp + "-" + part, num, target, ans);
                // multiplication (fix precedence)
                dfs(i + 1, curVal - preVal + preVal * val, preVal * val, exp + "*" + part, num, target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(0, 0, 0, "", num, target, ans);
        return ans;
    }
};

int main() {
    string num;
    int target;
    cin >> num >> target;

    Solution s;
    vector<string> res = s.addOperators(num, target);

    for (string &expr : res) {
        cout << expr << "\n";
    }
    return 0;
}
