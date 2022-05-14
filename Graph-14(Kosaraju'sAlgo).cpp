// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfsTopo(int node,vector<int> &vis,vector<int> adj[],stack<int> &st) {
	    vis[node]=1;
	    for(auto it:adj[node]) {
	        if(!vis[it]) {
	            dfsTopo(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	void dfs(int node,vector<int> &vis,vector<int> adj[]) {
	    vis[node]=1;
	    for(auto it:adj[node]) {
	        if(!vis[it]) {
	            dfs(it,vis,adj);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        vector<int> vis(v,0);
        stack<int> st;
        for(int i=0;i<v;i++) {
            if(!vis[i]) {
                dfsTopo(i,vis,adj,st);
            }
        }
        for(int i=0;i<v;i++) {
            vis[i]=0;
        }
        vector<int> trans[v];
        for(int i=0;i<v;i++) {
            for(auto x:adj[i]) {
                trans[x].push_back(i);
            }
        }
        int ans=0;
        while(!st.empty()) {
            auto x=st.top();
            st.pop();
            if(!vis[x]) {
                ans++;
                dfs(x,vis,trans);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
