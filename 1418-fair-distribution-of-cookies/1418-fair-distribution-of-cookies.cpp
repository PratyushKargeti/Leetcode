class Solution {
public:
    int solve(vector<int>&cookies,vector<int>&sums,int k,int ind,int zerocount)
    {
        if(cookies.size()-ind<zerocount)
            return INT_MAX;
        if(ind==cookies.size())
        {
            return *max_element(sums.begin(),sums.end());
        }

        int res=INT_MAX;
        for(int i=0;i<k;i++)
        {
            if(sums[i]==0)
                zerocount--;
            sums[i]+=cookies[ind];
            res=min(res,solve(cookies,sums,k,ind+1,zerocount));
            sums[i]-=cookies[ind];
            if(sums[i]==0)
                zerocount++;
        }
        return res;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> sums(k,0);
        return solve(cookies,sums,k,0,k);
    }
};