// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &bfs_res) {
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()) {
            auto x=q.front();
            bfs_res.push_back(x);
            q.pop();
            for(auto y:adj[x]) {
                if(!vis[y]) {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> bfs_res;
        vector<int> vis(v,0);
        bfs(0,adj,vis,bfs_res);
        return bfs_res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
