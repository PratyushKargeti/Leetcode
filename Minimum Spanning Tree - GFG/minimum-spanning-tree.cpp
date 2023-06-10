//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
public:
    vector<int> parent;
    vector<int> size;
    
    void make(int v) 
    {
        parent[v] = v;
        size[v] = 1;
    }
    
    int find(int v) 
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    
    void unionSet(int x, int y) 
    {
        int a = find(x);
        int b = find(y);
        if (a != b) 
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
    static bool compare(vector<int>& a, vector<int>& b) 
    {
        return a[2] < b[2];
    }
    
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) 
    {
        parent.resize(V);
        size.resize(V);
        for (int i = 0; i < V; i++)
            make(i);
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < adj[i].size(); j++) 
            {
                int u = i;
                int v = adj[i][j][0];
                int w = adj[i][j][1];
                edges.push_back({u, v, w});
            }
        }
        
        sort(edges.begin(), edges.end(), compare);
        
        int mincost = 0;
        
        for (int i = 0; i < edges.size(); i++) 
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            int x = find(u);
            int y = find(v);
            
            if (x != y) 
            {
                mincost += w;
                unionSet(u, v);
            }
        }
        
        return mincost;
    }
};



//{ Driver Code Starts.


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