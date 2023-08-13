class Solution {
public:
    int findfirst(int num)
    {
        int rem;
        while(num)
        {
            rem=num%10;
            num/=10;
        }
        return rem;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int x=findfirst(nums[i]);
                int y=nums[j]%10;
                int gcd=__gcd(x,y);
                if(gcd==1)
                    count++;
            }
        }
        return count;
    }
};