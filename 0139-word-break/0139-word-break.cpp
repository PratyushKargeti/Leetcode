class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set(wordDict.begin(),wordDict.end());
        vector<bool>visited(s.size(),false);
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int start=q.front();
            q.pop();
            if(start==s.size()) return true;
            for(int end=start+1;end<=s.size();end++)
            {
                if(visited[end]==false)
                {
                    if(set.find(s.substr(start,end-start))!=set.end())
                    {
                        q.push(end);
                        visited[end]=true;
                    }
                }
            }
        }
        return false;
    }
};