// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfs_res) {
        if(!vis[node]) {
            vis[node]=1;
            dfs_res.push_back(node);
            for(auto x:adj[node]) {
                if(!vis[x]) {
                    dfs(x,adj,vis,dfs_res);
                }
            }
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> dfs_res;
        vector<int> vis(v,0);
        dfs(0,adj,vis,dfs_res);
        return dfs_res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
