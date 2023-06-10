class Solution {
public:
    int missingNumber(vector<int>& a) {
        vector<int>b;
        for(int i=0;i<=a.size();i++)
        {
            b.push_back(i);
        }
        map<int,int>mp;
        for(int i=0;i<b.size();i++)
        {
            mp[b[i]]++;
        }
        for(int i=0;i<a.size();i++)
        {
            mp[a[i]]--;
        }
        int ans;
        for(auto i:mp)
        {
            if(i.second!=0)
                ans=i.first;
        }
        return ans;
    }
};