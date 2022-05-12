// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoBfs(vector<int> adj[],vector<int> &indegree,vector<int> &topoRes) {
	    queue<int> q;
	    for(int i=0;i<indegree.size();i++) {
	        if(indegree[i]==0) {
	            q.push(i);
	        }
	    }
	    while(!q.empty()) {
	        auto x=q.front();
	        q.pop();
	        topoRes.push_back(x);
	        for(auto it:adj[x]) {
	            indegree[it]--;
	            if(indegree[it]==0) {
	                q.push(it);
	            }
	        }
	    }
	}
	void topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(v,0);
	    vector<int> topoRes;
	    for(int i=0;i<v;i++) {
	        for(auto it:adj[i]) {
	            indegree[it]++;
	        }
	    }
	    topoBfs(adj,indegree,topoRes);
	    if(topoRes.size==v) {
	    	cout<<"NO-CYCLE"<<endl;
		}
		else {
			cout<<"CYCLE-EXISTS"<<endl;
		}
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
