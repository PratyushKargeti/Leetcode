class Solution {
public:
    void dfs(int u,vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[u]=true;
        for(int v=0;v<adj.size();v++)
        {
            if(adj[u][v]==1 && visited[v]==false)
            {
                dfs(v,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int count=0;
        int V=adj.size();
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};