class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>S;
        S.insert(nums.begin(),nums.end());
        if(S.size()!=nums.size())
            return true;
        else
            return false;
    }
};