class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> color(V,-1);
        queue<int>q;
        for(int i=0;i<V;i++) 
        {
            if(color[i]==-1) 
            {
                color[i]=0; //we can do this part in other fn too..i is current source as graph can be disconnected
                q.push(i);
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    for(int v=0;v<adj[u].size();v++)
                    {
                        if(color[adj[u][v]]==-1)
                        {
                            color[adj[u][v]]=1-color[u];
                            q.push(adj[u][v]);
                        }
                        else if(color[adj[u][v]]==color[u])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};