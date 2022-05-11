// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool checkBipartiteBfs(int node,vector<int> adj[],vector<int> &colour) {
        colour[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            auto x=q.front();
            q.pop();
            for(auto it:adj[x]) {
                if(colour[it]==-1) {
                    colour[it]=1-colour[x];
                    q.push(it);
                }
                else if(colour[it]==colour[x]) {
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int> colour(v,-1);
	    for(int i=0;i<v;i++) {
	        if(colour[i]==-1) {
	            if(!checkBipartiteBfs(i,adj,colour)) {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
