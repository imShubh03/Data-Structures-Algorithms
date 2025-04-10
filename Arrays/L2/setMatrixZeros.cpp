#include <bits/stdc++.h>
using namespace std;

/* brute force : time:O ((m*n)*(m+n)) space:O(1)
class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int i, int m, int n) {
        //mark row i as -1
        for(int j =0; j<n; j++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -1;
            }
        }
    }
    void markCol(vector<vector<int>>& matrix, int j, int m, int n){
        //mark col
        for(int i =0; i<m; i++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -1;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, i, m, n);
                    markCol(matrix, j, m, n);
                }
            }
        }


        //now mark all -1 to 0
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
*/

/*  TC :O(m*n)  SC:O(m) + O(n)
class Solution{
    public:
    void zeroMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();


        vector<int>row(m, 0), col(n, 0);

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
*/

class Solution {
    public:
    void zeroMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;

        // Mark the rows and columns that need to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // Mark the ith row
                    matrix[i][0] = 0;
                    // Mark the jth column, but consider the exception
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        // Traverse the matrix from row 1 and column 1
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // Check for the first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Check for the first column
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    Solution sol;
    sol.zeroMatrix(matrix);

    cout << "The final matrix is:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
