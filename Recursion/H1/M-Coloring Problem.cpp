#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int node, vector<vector<int>> &adj, int col, vector<int> &color)
    {
        for (auto it : adj[node])
        {
            if (color[it] == col)
                return false;
        }
        return true;
    }

    bool solve(int node, vector<vector<int>> &adj, vector<int> &color, int m, int v)
    {
        if (node == v)
            return true;

        for (int i = 1; i <= m; i++)
        {
            if (isPossible(node, adj, i, color))
            {
                color[node] = i;
                if (solve(node + 1, adj, color, m, v))
                    return true;
                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adj(v);
        for (auto it : edges)
        {
            int u = it[0], w = it[1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        vector<int> color(v, 0);
        return solve(0, adj, color, m, v);
    }
};

int main()
{
    int v, e, m;
    cin >> v >> e >> m;

    vector<vector<int>> edges(e, vector<int>(2));
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;

    if (sol.graphColoring(v, edges, m, color))
    {
        cout << "True" << endl;

        //followup print
        cout << "Color assignment: ";
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << " -> Color " << color[i] << "  ";
        }
        cout << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
