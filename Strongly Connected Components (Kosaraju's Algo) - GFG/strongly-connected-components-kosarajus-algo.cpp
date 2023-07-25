//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void dfs(int u,vector<vector<int>>&adj,stack<int>&s,vector<int>&visited)
	{
	   visited[u]=1;
	   for(int v:adj[u])
	   {
	       if(!visited[v])
	            dfs(v,adj,s,visited);
	   }
	   s.push(u);
	}
	
	void dfs2(int u,vector<vector<int>>&adjR,vector<int>&visited)
	{
	   visited[u]=1;
	   for(int v:adjR[u])
	   {
	       if(!visited[v])
	           dfs2(v,adjR,visited);
	   }
	}
	
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>visited(V,0);
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,s,visited);
            }
        }
        
        vector<vector<int>>adjR(V);
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            for(int j:adj[i])
            {
                adjR[j].push_back(i);
            }
        }
        
        int scc=0;
        while(!s.empty())
        {
            int u=s.top();
            s.pop();
            if(!visited[u])
            {
                scc++;
                dfs2(u,adjR,visited);
            }
        }
        return scc;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

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