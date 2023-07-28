class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            //new index position after any no. of deletion(count) will always be i-count
            int new_ind=i-count;
            if(new_ind%2==0 && nums[i]==nums[i+1])
                count++;
        }
        //if after all deletions,array is still odd length,then one more delete operation
        if((nums.size()-count)%2==1) return count+1;
        return count;
    }
};