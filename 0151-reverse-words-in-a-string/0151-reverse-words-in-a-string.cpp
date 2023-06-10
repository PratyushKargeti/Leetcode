class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>v;
        string word;
        while(ss>>word)
        {
            v.push_back(word);
        }
        reverse(v.begin(),v.end());
        string ans="";
        for(int i=0;i<v.size();i++)
        {
            ans+=v[i]+" ";
        }
        ans.erase(ans.size()-1);
        return ans;
    }
};