// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool checkBipartiteDfs(int node,vector<int> adj[],vector<int> &colour) {
        if(colour[node]==-1) {
            colour[node]=1;
        }
        for(auto it:adj[node]) {
            if(colour[it]==-1) {
                colour[it]=1-colour[node];
                if(!checkBipartiteDfs(it,adj,colour)) {
                    return false;
                }
            }
            else if(colour[it]==colour[node]) {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int v, vector<int> adj[]){
	    // Code here
	    vector<int> colour(v,-1);
	    for(int i=0;i<v;i++) {
	        if(colour[i]==-1) {
	            if(!checkBipartiteDfs(i,adj,colour)) {
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
