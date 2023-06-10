class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>S;
        S.insert(nums.begin(),nums.end());
        auto it=S.begin();
        if(S.size()==1)
            advance(it,0);
        else if(S.size()==2)
            advance(it,1);
        else
            advance(it,S.size()-3);
        return *(it);
    }
};