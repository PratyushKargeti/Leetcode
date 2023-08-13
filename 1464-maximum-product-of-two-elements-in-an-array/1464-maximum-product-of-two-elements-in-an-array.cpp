class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long l=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                long long prod=(nums[i]-1)*(nums[j]-1);
                if(prod>l)
                    l=prod;
            }
        }
        return l;
    }
};