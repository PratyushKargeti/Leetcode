class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
        vector<int>adj[N];
	    for(auto&i:pre)
	    {
	        adj[i[1]].push_back(i[0]);
	    }
	    vector<int>indegree(N,0);
        for(int u=0;u<N;u++)
        {
            for(int v:adj[u])
            {
                indegree[v]++;
            }
        }
        queue<int>q;
        for(int i=0;i<N;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        if(ans.size()!=N)
            return {};
        return ans;
    }
};