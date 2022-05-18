// { Driver Code Starts
// Initial template for C++

//Rat in a Maze (DFS-Approach)
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int vis[10][10];
class Solution{
    public:
    void dfs(int x,int y,vector<vector<int>> m,int n,vector<string> &ans,string curr,string step)
    {
    	//This should be the first step or else out of bound indexes of array may be accesed(=>Segmentation fault)
        if(x<0 || y<0 || x>=n || y>=n) {
            return;
        }
        if(m[x][y]==0 || vis[x][y]==1) {
            return;
        }
        if(x==n-1 && y==n-1) {
            curr+=step;
            ans.push_back(curr);
            return;
        }
        curr+=step;
        vis[x][y]=1;
        dfs(x+1,y,m,n,ans,curr,"D");
        dfs(x-1,y,m,n,ans,curr,"U");
        dfs(x,y+1,m,n,ans,curr,"R");
        dfs(x,y-1,m,n,ans,curr,"L");
        
        //Relaxing the position for reusing the point for another possible path
        vis[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0) {
            string st="-1";
            ans.push_back(st);
            return ans;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                vis[i][j]=0;
            }
        }
        string curr;
        string ch;
        dfs(0,0,m,n,ans,curr,ch); 
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
