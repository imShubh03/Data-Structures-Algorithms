#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&component){
        vis[node] = 1;
        component.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, component);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>> ans;
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                vector<int> component;
                dfs(i, adj, vis, component);
                ans.push_back(component);
            }
        }
        
        return ans;
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));
    for(int i=0; i<E; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    vector<vector<int>> comps = obj.getComponents(V, edges);

    for(auto &comp : comps){
        for(int node : comp){
            cout << node << " ";
        }
        cout << endl;
    }
}
