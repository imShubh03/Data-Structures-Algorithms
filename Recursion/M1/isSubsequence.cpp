#include<bits/stdc++.h>
using namespace std;

/* TC : O(m * 2^m) + O(n* 2^m) SC:(m * 2^m)
class Solution {
public:
    void generate(string &t, int index, string &temp, vector<string>&subseq){
        if(index == t.size()){
            subseq.push_back(temp);
            return;
        }

        temp.push_back(t[index]);
        generate(t, index + 1, temp, subseq);
        temp.pop_back();

        generate(t, index + 1, temp, subseq);
    }

    bool isSubsequence(string s, string t) {
        vector<string>subseq;
        string temp = "";
        generate(t, 0, temp, subseq);

        for(string &st : subseq){
            if(st == s){
                return true;
            }
        }
        return false;
    }
};
*/

//TC:O(m + n) SC:O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while( i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};

int main(){
    string s, t;
    cin >> s >> t;

    Solution obj;
    cout << obj.isSubsequence(s, t) << endl;
}
