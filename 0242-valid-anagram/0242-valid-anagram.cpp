class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_map<string,vector<string>>mp;
        // string s1=s;
        // string s2=t;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // mp[s].push_back(s1);
        // mp[t].push_back(s2);
        // vector<vector<string>>res;
        // for(auto i :mp)
        // {
        //     vector<string> v= i.second;
        //     res.push_back(v);
        // }
        // if(res.size()==1)
        //     return true;
        // return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
            return true;
        return false;

    }
};