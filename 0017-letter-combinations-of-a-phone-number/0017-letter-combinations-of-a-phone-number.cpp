class Solution {
public:
    void solve(int ind,string&temp,vector<string>&ans,unordered_map<char,string>&m,string &s)
    {
        if(ind==s.size())
        {
            ans.push_back(temp);
            return;
        }
        string str=m[s[ind]];
        for(int i=0;i<str.size();i++)
        {
            temp.push_back(str[i]);
            solve(ind+1,temp,ans,m,s);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        if(s.empty()) return {};
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string>ans;
        string temp;
        solve(0,temp,ans,m,s);
        return ans;
    }
};