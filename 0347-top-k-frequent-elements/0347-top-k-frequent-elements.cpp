class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<int>sizes;
        for(auto i:m)
        {
            sizes.push_back(i.second);
        }
        sort(sizes.begin(),sizes.end(),greater<int>());
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            for(auto ob:m)
            {
                if(ob.second==sizes[i])
                    ans.push_back(ob.first);                    
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};