class Solution {
public:
//Count how many pairs in nums have a difference equal to or less than mid
    int countpairs(int mid,vector<int>&nums)
    {
        int count=0;
        for(int i=0;i<nums.size()-1;)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                count++;
                i++;
            }
            i++;
        }
        return count;

    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0;
        int high=nums[n-1]-nums[0];
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(countpairs(mid,nums)>=p)
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};