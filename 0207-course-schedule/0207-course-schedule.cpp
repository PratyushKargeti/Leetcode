class Solution {
public:
    bool topological_sort(vector<int> adj[],int V) 
    {
        vector<int> indegrees(V,0); // initialize indegrees to 0 for all vertices
        for (int u = 0; u<V; u++) 
        {
            for (int v : adj[u]) 
                indegrees[v]++; // calculate indegrees of each vertex
        }
        queue<int> q;
        for(int u = 0; u<V; u++) 
        {
            if (indegrees[u] == 0) 
                q.push(u); // add vertices with 0 indegree to the queue
        }
        vector<int> topo;
        while(q.empty()==false) 
        {
            int u = q.front();
            q.pop();
            topo.push_back(u); // add vertex to the topological order
            for(int v : adj[u]) 
            {
                indegrees[v]--; // decrement indegree of all neighbors
                if (indegrees[v] == 0) 
                    q.push(v); // add neighbor to the queue if it has 0 indegree
            }
        }
        if(topo.size() != V)
            return false; 
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<int>adj[V];
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
        }   
        return topological_sort(adj,V);
    }
};