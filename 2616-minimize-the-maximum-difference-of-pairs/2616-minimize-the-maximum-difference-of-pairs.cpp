class Solution {
public:
//Check if count of pairs in nums having a difference equal to or less than threshold mid(possible answer) is greater than equal to p
    //greedy provides larger subarray for finding the next pair
    bool count_verifypairs(int mid,vector<int>&nums,int p)
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
        return count>=p;

    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end()); //greedy approach will always yield the maximum number of valid pairs.
        int n=nums.size();
        int low=0;
        int high=nums[n-1]-nums[0];
        while(low<high) //at low>=high, we will have our answer stored in row
        {
            int mid=low+(high-low)/2;
            //given threshold mid, we determine if there exist at least p valid pairs?
            if(count_verifypairs(mid,nums,p))
            {
                high=mid; //look for more less answer in left part 
            }
            else
            {
                low=mid+1; //look for more greatwer answer in right part
            }
        }
        return low;
    }
};