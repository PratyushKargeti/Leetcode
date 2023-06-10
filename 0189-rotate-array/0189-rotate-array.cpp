class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        int c=k%n;
        for(int i=n-c;i<n;i++)
            ans.push_back(nums[i]);
        for(int i=0;i<n-c;i++)
            ans.push_back(nums[i]);
        for(int i=0;i<ans.size();i++)
            nums[i]=ans[i];
        return;
    }

};