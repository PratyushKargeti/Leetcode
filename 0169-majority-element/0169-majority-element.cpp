class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //O(N^2)
        // int key=ceil(nums.size()/2);
        // int i;
        // for(i=0;i<nums.size();i++)
        // {
        //     if(count(nums.begin(),nums.end(),nums[i])>key)
        //         break;
        // }
        // return nums[i];
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return(nums[n/2]);
    
    }
};