class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxreach = 0; //in beginning maximum reachable index is 0
        for(int i=0;i<n;i++)
        {
            //current index is i
            //if our maximum reach is less than current index, it means we cannot reach current index..straight away return false
            if(maxreach<i) return false;

            //updating max reach for every current index
            maxreach=max(maxreach,i+nums[i]); //we can be sure that i+nums[i] will hold new maximum reachable index because we have already checked above that we will definitely reach this current index

            //if at any point maxreach reaches last index,break early to return true
            if(maxreach>=n-1) break;
        }
        return true;
    }
};