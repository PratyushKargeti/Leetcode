class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto i: m)
        {
            if(i.second==1)
                return i.first;
        }
        return -1;
        
        // int Xor=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     Xor^=nums[i];
        // }
        // return Xor;
    }
};