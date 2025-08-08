#include<bits/stdc++.h> 
using namespace std;

/* TC:O(n * n!)  SC: O(n^2)
class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int duprow = row;
        int dupcol = col;

        // we only check for 3 directions 
        // Check for upper back diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;
        // Check for previous columns in the same row
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        // Check for lower back diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        // Base case
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                // Backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};
*/


class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& res, vector<int>& leftRow, vector<int>& upperD, vector<int>& lowerD, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && upperD[n - 1 + col - row] == 0 && lowerD[row + col] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperD[n - 1 + col - row] = 1;
                lowerD[row + col] = 1;

                // ✅ Corrected argument order here
                solve(col + 1, board, res, leftRow, upperD, lowerD, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                upperD[n - 1 + col - row] = 0;
                lowerD[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperD(2 * n - 1, 0), lowerD(2 * n - 1, 0);
        solve(0, board, res, leftRow, upperD, lowerD, n);
        return res;
    }
};


int main() {
    Solution sol;
    int n = 4; 
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total number of solutions for " << n << "-Queens: " << solutions.size() << endl;

    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
