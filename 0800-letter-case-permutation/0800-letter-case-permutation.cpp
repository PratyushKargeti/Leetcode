class Solution {
public:
    vector<string>ans;
    void solve(string s,int ind)
    {
        if(ind==s.size())
        {
            ans.push_back(s);
            return;
        }
        solve(s,ind+1);
        if(isalpha(s[ind]))
        {
            s[ind] ^= 32;
            solve(s, ind + 1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,0);
        return ans;
    }
};