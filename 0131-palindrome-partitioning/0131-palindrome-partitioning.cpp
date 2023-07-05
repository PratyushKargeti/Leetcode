class Solution {
public:
    bool ispallindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int ind,vector<string>&ds,vector<vector<string>>&ans,string s)
    {
        if(ind==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(ispallindrome(s,ind,i))
            {
                ds.push_back(s.substr(ind,i-ind+1));
                solve(i+1,ds,ans,s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        solve(0,ds,ans,s);
        return ans;
    }
};