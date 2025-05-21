#include<bits/stdc++.h>
using namespace std;

/*Brute TC: O(N* K logk)  sort str of len k SC:O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
*/

// TC O(n * k) SC O(n * k)
class Solution {
    public:
    string generateWord(string &s){
        int arr[26] = {0};
        for(char &ch: s)  {
            arr[ch - 'a']++;
        }

        string newWrd = "";
        for(int i = 0; i < 26; i++){
            int freq = arr[i];
            if(freq > 0){
                newWrd += string(freq, i + 'a');
            }
        }
        return newWrd;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs){
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(int i = 0; i < n; i++){
            string word = strs[i];
            string newWord = generateWord(word);
            mp[newWord].push_back(word);
        }
        
        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};


int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution obj;
    vector<vector<string>> result = obj.groupAnagrams(strs);

    for(auto group : result) {
        for(auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
