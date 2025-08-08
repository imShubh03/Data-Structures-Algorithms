#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
void solve(string &digits, int index, string &curr, vector<string>& map, vector<string>& res) {
    if(index >= digits.length()) {
        res.push_back(curr);
        return;
    }

    int num = digits[index] - '0';
    string temp = map[num];

    for(int i = 0; i < temp.size(); i++) {
        curr.push_back(temp[i]);
        solve(digits, index + 1, curr, map, res);
        curr.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string curr = "";
    vector<string> res;
    if(digits.length() == 0) return res;
    solve(digits, 0, curr, map, res);
    return res; 
    }
};

int main() {
    Solution sol;
    string digits;
    cout << "Enter the digits: ";
    cin >> digits;

    vector<string> combinations = sol.letterCombinations(digits);

    cout << "Possible letter combinations are:" << endl;
    for ( auto combo : combinations) {
        cout << combo << endl;
    }

    return 0;
}
