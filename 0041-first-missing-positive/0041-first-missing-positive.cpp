class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>S;
        S.insert(nums.begin(),nums.end());
        for(int i=1;;i++)
        {
            if(S.count(i)==0)
                return i;
        }
    }
};