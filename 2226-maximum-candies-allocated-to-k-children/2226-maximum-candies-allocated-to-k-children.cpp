class Solution {
public:
//(4,8,6,2,3),c=4,k=3
//(4,7,3),c=3,k=4 
    bool possible(int c,vector<int>&nums,long long k)
    {   
        long long cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt+=nums[i]/c;   
        }
        if(cnt>=k) return true;
        return false;
    }
    //bs on answer
    int maximumCandies(vector<int>& nums, long long k) {
        if(accumulate(begin(nums),end(nums),0LL)<k) return 0; //bad case
        int low=1; //minimal candy one child can get
        int high=*max_element(begin(nums),end(nums));//maximal candy child can get
     //   int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            //check if it is possible to distribute 'mid' candies among 'k' children // Each child can take at most one pile of candy
            if(possible(mid,nums,k)) 
            {      
               // ans=mid;
                low=mid+1; //search for more maximum answer on right
            }
            else
            {
                high=mid-1; //look for lesser answer on left
            }
        }
        //return ans;
        return high; //OMG
    }
};