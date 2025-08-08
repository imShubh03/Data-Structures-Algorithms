#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(string &s, int index, vector<string>&path, vector<vector<string>>&res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        solve(s, 0, path, res);
        return res;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    vector<vector<string>> ans = obj.partition(s);

    for(auto &partition : ans) {
        for(auto &str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
