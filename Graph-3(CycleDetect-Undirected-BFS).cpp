// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int node,vector<int> adj[],vector<int> &vis) {
        queue<pair<int,int>> q;
        q.push({node,-1});
        vis[node]=1;
        while(!q.empty()) {
            auto x=q.front().first;
            auto par=q.front().second;
            q.pop();
            for(auto y:adj[x]) {
                if(!vis[y]) {
                    q.push({y,x});
                    vis[y]=1;
                }
                else if(par!=y) {
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> vis(v,0);
        for(int i=0;i<v;i++) {
            if(!vis[i]) {
                if(checkCycle(i,adj,vis)){
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
