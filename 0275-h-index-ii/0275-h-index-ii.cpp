class Solution {
public:
    int hIndex(vector<int>& nums) {
        int i=1;
        vector<int>res;
        sort(nums.begin(),nums.end(),greater<int>());
        //6 5 3 1 0
        int count=0;
        while(i<=nums.size())
        {
            if(nums[i-1]>=i)
                count++;
            if(count==i)
                res.push_back(i);
            i++;
        }
        if(!(res.empty()))
            return res[res.size()-1];
        return 0;
    }
};