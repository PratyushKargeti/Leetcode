class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<int> vec;
        //for(auto i=mp.begin();i!=mp.end();i++)
        for(auto i:mp)
        {
            vector<int> v=mp[i.first];
            int k=v.size();
            vec.push_back(k);
        }
        for(int i=0;i<vec.size()-1;i++)
        {
            for(int j=i+1;j<vec.size();j++)
            {
                if(vec[i]==vec[j])
                    return false;
            }
        }
        return true;
    }
};