class Solution {
public:
    //all nodes in cycle will not be safe node
    //all nodes with have path to cycle node will not be safe node
    bool dfs(int u,vector<bool>&visited,vector<bool>&pathvisited,vector<vector<int>>&adj,vector<int>&check)
    {
        visited[u]=true;
        pathvisited[u]=true;
        check[u]=1; //consider root as safe node
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                if(dfs(v,visited,pathvisited,adj,check))
                {
                    check[u]=0; //cycle detected through root node->not safe
                    return true;
                }
            }
            else if(pathvisited[v]==true)
            {
                check[u]=0; //cycle detected through root node->not safe
                return true;
            }
        }
        check[u]=1; //cycle not found,root node safe
        pathvisited[u]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool>visited(V,false);
        vector<bool>pathvisited(V,false);
        vector<int>ans;
        vector<int>check(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,visited,pathvisited,graph,check); //call dfs on every unvisited vertice
            }
        }
        for(int j=0;j<V;j++)
        {
            if(check[j]==1)
                ans.push_back(j);
        }            
        return ans;
    }
};