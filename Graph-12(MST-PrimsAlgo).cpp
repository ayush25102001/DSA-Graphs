// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        vector<int> par(v,-1);
        vector<int> key(v,INT_MAX);
        vector<int> MST(v,0);
        key[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        pq.push({0,0});
        while(!pq.empty()) {
            auto x=pq.top();
            int node=x.second;
            int node_key=x.first;
            pq.pop();
            MST[node]=1;
            for(auto it:adj[node]) {
                int n=it[0];
                int n_wgt=it[1];
                if(MST[n]==0 && n_wgt<key[n]) {
                    key[n]=n_wgt;
                    pq.push({n_wgt,n});
                }
            }
        }
        int ans=0;
        for(int i=0;i<v;i++) {
            ans+=key[i];
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
