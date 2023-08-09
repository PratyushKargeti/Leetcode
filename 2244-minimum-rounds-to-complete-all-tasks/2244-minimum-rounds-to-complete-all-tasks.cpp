class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return -1;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int cnt=0;
        for(auto i:m)
        {
            if(i.second==1) return -1;
            if(i.second==2 || i.second==3) cnt++;
            else
            {
                cnt+=ceil((double)i.second/3);
            }
        }
        return cnt;
    }
};