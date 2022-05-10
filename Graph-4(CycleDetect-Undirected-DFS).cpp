// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int node,int par,vector<int> adj[],vector<int> &vis) {
        vis[node]=1;
        for(auto x:adj[node]) {
            if(!vis[x]) {
                if(checkCycle(x,node,adj,vis)) {
                    return 1;
                }
            }
            else if(par!=x) {
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,0);
        for(int i=0;i<v;i++) {
            if(!vis[i]) {
                if(checkCycle(i,-1,adj,vis)){
                    return 1;
                }
            }
        }
        return 0;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
