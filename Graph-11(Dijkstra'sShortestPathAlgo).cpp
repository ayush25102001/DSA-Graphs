class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int> distTo(v,INT_MAX);
        distTo[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        pq.push({0,s});
        vector<int> vis(v,0);
        while(!pq.empty()) {
            auto x=pq.top();
            int dis=x.first;
            int node=x.second;
            pq.pop();
    	    if(vis[node] == 1) {
    		    continue;
    	    }
    	    vis[node] = 1;
            for(auto it:adj[node]){     
                int dis_it=it[1];
                int n_it=it[0];
                if(distTo[n_it]>(distTo[node]+dis_it)) {
                    distTo[n_it]=distTo[node]+dis_it;
                    pq.push({distTo[n_it],n_it});
                }
            }
        }
        return distTo;
    }
};
