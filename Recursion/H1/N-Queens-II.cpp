#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int duprow = row;
        int dupcol = col;

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

    void solve(int col, vector<string>& board, int& count, int n) {
        // Base case
        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, count, n);
                // Backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        solve(0, board, count, n);
        return count; // Return the total number of solutions
    }
};

int main() {
    Solution sol;
    int n = 4; 
    int result = sol.totalNQueens(n);

    cout << "Total number of solutions for " << n << "-Queens: " << result << endl;

    return 0;
}
