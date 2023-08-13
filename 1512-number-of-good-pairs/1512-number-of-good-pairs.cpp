class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // int count=0,i,j;
        // for(i=0;i<nums.size()-1;i++)
        //     for(j=i+1;j<nums.size();j++)
        //         if(nums[i]==nums[j])
        //             count++;
        // return count;
        // map<int,vector<int>> MAP;
        // for(int i=0;i<nums.size();i++)
        // {
        //     MAP[nums[i]].push_back(i);
        // }
        // int count=0;
        // for(auto i:MAP)
        // {           
        //     count+=((i.second.size())*(i.second.size()-1)/2);
        //    // cout<<i.second.size()<<" "<< count <<endl;      
        // }
        // return count;
        map<int,int>m;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto i:m)
        {
            ans+=i.second*(i.second-1)/2;
        }
        return ans;
    }
};