class Solution {
public:
    void solve(int ind,int count,vector<int>&in,vector<vector<int>>&requests,int n,int &ans)
    {
        if(ind==requests.size())
        {
            for(int i=0;i<n;i++)
            {
                if(in[i]!=0)
                    return;
            }
            ans=max(ans,count); 
            return;           
        }
        //pick
        in[requests[ind][0]]--;
        in[requests[ind][1]]++;
        solve(ind+1,count+1,in,requests,n,ans);
        in[requests[ind][0]]++;
        in[requests[ind][1]]--;
        //not pick
        solve(ind+1,count,in,requests,n,ans);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>in(n);
        int ans=0;
        solve(0,0,in,requests,n,ans);
        return ans;
    }
};