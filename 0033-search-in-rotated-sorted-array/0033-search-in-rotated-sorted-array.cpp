class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int high=nums.size()-1;
        // int low=0;
        // while(low<=high)
        // {
        //     int mid=low+(high-low)/2;
        //     if(nums[mid]==target)
        //         return mid;
        //     else if(nums[mid]>target)
        //         high=mid-1;
        //     else
        //         low=mid+1;
        // }
        // return -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
                return i;
        }
        return -1;
    }
};