class Solution {
public:    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++)
        {
            int sum=queries[i];
            int count=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]<=sum) 
                {
                    sum-=nums[j];
                    count++; 
                }
            }
            res.push_back(count);
        } 
        return res;
    }
};