#include<bits/stdc++.h>
using namespace std;

/*app 1 : brute : time:O(2^(2n) * 2n) space:O(2n)
class Solution {
public:
    bool isValid(string &str){
        int cnt = 0;
        for(char ch : str){
            if(ch == '(') cnt++;
            else cnt--;
            // edge case for '())('
            if(cnt < 0){
                return false;
            }
        }
        return cnt == 0;
    }
    void solve(string &ans, vector<string> &res, int n){
        // base case
        if(ans.size() == 2 * n){
            // check if it's valid
            if(isValid(ans)){
                res.push_back(ans); // Push valid parenthesis string to the result
            }
            return;
        }
        // for pick '('
        ans.push_back('('); // Add '(' to the current string
        solve(ans, res, n);
        ans.pop_back(); // Remove last character to backtrack

        // for pick ')'
        ans.push_back(')'); // Add ')' to the current string
        solve(ans, res, n);
        ans.pop_back(); // Remove last character to backtrack
    }

    vector<string> generateParenthesis(int n) {
        string ans = "";
        vector<string> res;
        solve(ans, res, n);
        return res; 
    }
};
*/


//approach 2 time:O(2^(2n)) space:O(2n)
class Solution {
public:
    void solve(string &ans, vector<string> &res, int n, int open, int close){
        // base case
        if(ans.size() == 2 * n){
            res.push_back(ans); // Push valid parenthesis string to the result
            return;
        }

        // for pick '('
        if(open<n){
            ans.push_back('(');
            solve(ans, res, n, open+1, close);
            ans.pop_back();
        }

        // for pick ')'
        if(close < open){
            ans.push_back(')'); 
            solve(ans, res, n, open, close+1);
            ans.pop_back(); 
        }
    
    }
    vector<string> generateParenthesis(int n) {
        string ans = "";
        vector<string> res;
        int open=0;
        int close=0;
        solve(ans, res, n, open, close);
        return res; 
    }
};

int main() {
    Solution solution;
    int n = 3; // Example input
    vector<string> result = solution.generateParenthesis(n);

    // Print the result
    cout << "Valid Parentheses Combinations for n = " << n << ":" << endl;
    for( string s : result) {
        cout << s << endl;
    }

    return 0;
}
