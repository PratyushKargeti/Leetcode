class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       auto it=max_element(nums.begin(),nums.end());
       int i;
       for(i=0;i<nums.size();i++)
       {
           if(nums[i]==*it)
           {
               break; 
           }
       }
       return i;
    }
};