class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int pattern=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1]) //if monotone increasing
            {
                if(pattern==0)
                    pattern=1; //set increasing status
                else if(pattern==-1) // if found decreasing status in btw
                    return false; 
            }
            else if(nums[i]>nums[i+1]) //if monotone decreasing
            {
                if(pattern==0)
                    pattern=-1; //set decreasing status
                else if(pattern==1) //if found increasing status in btw
                    return false;
            }
        } //nums[i]==nums[i+1] case is always true
        return true;
    }
};