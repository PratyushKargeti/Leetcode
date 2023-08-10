class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto i:mp)
        {
            vector<string> v= i.second;
            ans.push_back(v);
        }
        return ans;
    }
};