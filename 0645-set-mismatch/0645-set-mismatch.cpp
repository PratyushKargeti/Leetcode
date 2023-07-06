class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        set<int>S;  
        S.insert(nums.begin(),nums.end());
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto i:m)
        {
            if(i.second==2)
            {
                ans.push_back(i.first);
                break;
            }
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(S.find(i)==S.end())
            {    
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};