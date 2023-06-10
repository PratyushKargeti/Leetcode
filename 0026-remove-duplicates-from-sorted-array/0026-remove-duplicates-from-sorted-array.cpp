class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> S;
        S.insert(nums.begin(),nums.end());
        vector<int> expectedNums;
        for(auto it=S.begin();it!=S.end();it++)
        {
            expectedNums.push_back(*it);
        }
        int k=S.size();
        for (int i = 0; i < k; i++) 
            nums[i]=expectedNums[i];
        return k;
    }
};