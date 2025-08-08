#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void solve(int i, int j, vector<vector<int>>& mat, int n, vector<string>& ans, string path, vector<vector<int>>& vis) {
        // Base case: If the destination (bottom-right corner) is reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);  
            return;
        }

        // Mark the current cell as visited
        vis[i][j] = 1;

        // Move Downward
        if (i + 1 < n && !vis[i + 1][j] && mat[i + 1][j] == 1) {
            solve(i + 1, j, mat, n, ans, path + 'D', vis);
        }

        // Move Left
        if (j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1] == 1) {
            solve(i, j - 1, mat, n, ans, path + 'L', vis);
        }

        // Move Right
        if (j + 1 < n && !vis[i][j + 1] && mat[i][j + 1] == 1) {
            solve(i, j + 1, mat, n, ans, path + 'R', vis);
        }

        // Move Upward
        if (i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j] == 1) {
            solve(i - 1, j, mat, n, ans, path + 'U', vis);
        }

        // Backtrack: Unmark the current cell as visited
        vis[i][j] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Start solving from the top-left corner if it's open
        if (mat[0][0] == 1) {
            solve(0, 0, mat, n, ans, "", vis);
        }

        return ans;
    }
};

int main() {
    // Initialize the matrix representing the maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Find all paths from top-left to bottom-right
    vector<string> paths = solution.findPath(maze);

    // Output the paths found
    if (paths.empty()) {
        cout << "No path found" << endl;
    } else {
        for (const string& path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}