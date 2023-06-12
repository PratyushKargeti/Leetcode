class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //low variable represents the lower bound of the search range, while high represents the upper bound. The binary search algorithm continually updates the values of low and high to narrow down the search range until the target element is found or the search range becomes empty.
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return low;// represents the index where the target element should be inserted to maintain the sorted order of the vector.
    }
};