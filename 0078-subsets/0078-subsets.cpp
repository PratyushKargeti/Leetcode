class Solution {
public:
    void getsub(vector<int>& nums,vector<int>& ss,vector<vector<int>>& res,int i)
    {
        if(i==nums.size())
        {
            res.push_back(ss);
            return;
        }
        else
        {
            ss.push_back(nums[i]);
            getsub(nums,ss,res,i+1);
            ss.pop_back();
            getsub(nums,ss,res,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ss;
        vector<vector<int>>res;
        getsub(nums,ss,res,0);
        return res;
    }
};
