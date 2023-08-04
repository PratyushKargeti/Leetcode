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
                    if(set.count(s.substr(start,end-start)))
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

// class Solution {
// private:
//     bool wordBreak(int start,vector<int>&dp,string s,unordered_set<string>&set) {
//         if(start == s.size()) return true;
//         if(dp[start] != -1) return dp[start];
//         for(int i=start; i<s.size();i++)
//         {
//             if(set.count(s.substr(start,i+1-start)) && wordBreak(i+1,dp,s,set))
//                 return dp[start]=true;
//         }
//         return dp[start]=false;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<int>dp(s.size(),-1);
//         unordered_set<string>set(wordDict.begin(),wordDict.end());
//         return wordBreak(0,dp,s,set);
//     }
// };