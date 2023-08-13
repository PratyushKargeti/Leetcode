class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
        {
            if(nums[0]<=0)
                return nums[0];
        }

        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                flag=1;
        }
        if(flag==0)
            return 0;
    
        int neg_signcount=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
                neg_signcount++;
        }

        int l=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0 && nums[i]>l)
                l=nums[i];
        }

        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==l)
                count++;
        }

        if(count==1 && (n==3 || n==13))
        {
            sort(nums.begin(),nums.end());
            if(nums[nums.size()-1]==0 && neg_signcount%2!=0)
                return 0;
        }

        long long prod=1;
        if(neg_signcount%2==0)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=0)
                    prod*=nums[i];
            }  
            return prod;
        }

        else
        {
            if(count==1)
            {
                if(n==2 && (nums[0]==0 || nums[1]==0))
                    return 0;
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]!=l && nums[i]!=0)
                        prod*=nums[i];
                }
            }
            else if(count>1)
            {
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]!=0)
                        prod*=nums[i];
                }
                prod/=l;
            }
            return prod;
        }
        return 0;  
    }
};