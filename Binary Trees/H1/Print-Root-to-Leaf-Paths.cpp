#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void solve(Node *node, vector<int> &path, vector<vector<int>> &res)
    {
        if (node == nullptr)
            return;

        path.push_back(node->data);

        if (node->left == NULL && node->right == NULL)
        {
            res.push_back(path);
        }
        else
        {
            solve(node->left, path, res);
            solve(node->right, path, res);
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> res;
        vector<int> path;
        solve(root, path, res);
        return res;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<vector<int>> paths = sol.Paths(root);

    for (auto path : paths)
    {
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
