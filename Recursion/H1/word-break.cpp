#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int index, string s, unordered_set<string>& wordDict) {
        if(index == s.length()) {
            return true;
        }

        string temp = "";
        for(int len = 1; index + len <= s.length(); len++) {
            temp = s.substr(index, len);
            if(wordDict.find(temp) != wordDict.end()) {
                if(solve(index + len, s, wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& words) {
        unordered_set<string> wordDict(words.begin(), words.end());
        return solve(0, s, wordDict);
    }
};

int main(){
    string s;
    int n;
    cin >> s >> n;
    vector<string> wordDict(n);
    for(int i=0; i<n; i++) cin >> wordDict[i];
    
    Solution obj;
    cout << (obj.wordBreak(s, wordDict) ? "true" : "false");
}
