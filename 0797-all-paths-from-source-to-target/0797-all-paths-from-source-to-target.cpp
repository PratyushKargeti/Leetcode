class Solution {
public:
    void dfs(int u,vector<int>&path,vector<vector<int>>&ans,vector<vector<int>>&graph){
        path.push_back(u);
        if(u==graph.size()-1)
            ans.push_back(path);
        else
        {
            for(int v:graph[u])
            {
                dfs(v,path,ans,graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(0,path,ans,graph);
        return ans;
    }
};