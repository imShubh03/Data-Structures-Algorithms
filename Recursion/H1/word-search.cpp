#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, vector<vector<int>>& vis, int m, int n, int i, int j, int index){
        if(index == word.size())
            return true;

        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;

        if(board[i][j] != word[index] || vis[i][j] == 1)
            return false;

        vis[i][j] = 1;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int d = 0; d < 4; d++){
            int i_ = i + dx[d];
            int j_ = j + dy[d];

            if(dfs(board, word, vis, m, n, i_, j_, index + 1))
                return true;
        }

        vis[i][j] = 0; // backtrack

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, vis, m, n, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    Solution obj;
    if(obj.exist(board, word)) cout << "true\n";
    else cout << "false\n";

    return 0;
}
