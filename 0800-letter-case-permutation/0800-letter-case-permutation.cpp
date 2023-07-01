class Solution {
public:
    vector<string>ans;
    void solve(string s,string str, int ind)
    {
        if(ind==s.size())
        {
            ans.push_back(str);
            return;
        }
        if(isalpha(s[ind]))
        {
            str+=toupper(s[ind]);
            solve(s,str,ind+1);
            str.pop_back();
            str+=tolower(s[ind]);
            solve(s,str,ind+1);
            str.pop_back();
        }
        else
        {
            str+=s[ind];
            solve(s,str,ind+1);
            str.pop_back();    
        }
    }
    vector<string> letterCasePermutation(string s) {
        string str="";
        solve(s,str,0);
        return ans;
    }
};