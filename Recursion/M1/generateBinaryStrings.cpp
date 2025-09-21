#include <bits/stdc++.h>
using namespace std;

/* TC : O(n * 2^n) SC:O(n) + O(n * 2^n)
class Solution{
    public:
    bool isValid(string &temp){
        // base case
        for(int i = 0; i< temp.size() -1; i++){
            if(temp[i] == '1' && temp[i] == temp[i+1]){
                return false;
            }
        }
        return true;
    }
    void generate(vector<string>&res, string &temp, int num){
        if(temp.size() == num){
            if(isValid(temp)){
                res.push_back(temp);
            }
            return;
        }
        //for '0'
        temp.push_back('0');
        generate(res, temp, num);
        temp.pop_back();
        
        //for '1'
        temp.push_back('1');
        generate(res, temp, num);
        temp.pop_back();
    }
    vector<string>generateBinaryStrings(int num){
        vector<string>res;
        string temp = "";
        generate(res, temp, num);
        return res;
    }
};
*/

// TC :O(n * valid strings) ie TC=O(N⋅f(N)) where f(N)=f(N−1)+f(N−2)  SC :O(n * valid strings)
class Solution {
    public:
    void generate(vector<string>&res, string &temp, int N){
    //base case
        if(temp.size() == N){
            res.push_back(temp);
            return;
        }
    
        // for '0'
        temp.push_back('0');
        generate(res, temp, N);
        temp.pop_back();
    
        //for 1 
        if(temp.size() == 0 || temp.back() != '1'){
            temp.push_back('1');
            generate(res, temp, N);
            temp.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int num) {
        vector<string>res;
        string temp = "";
        generate(res, temp, num);
        return res;
    }
};

int main() {
    int n;
    cin>>n;

    Solution sol;
    vector<string>ans = sol.generateBinaryStrings(n);

    for(string s : ans){
        cout << s << " ";
    }

    return 0;
}