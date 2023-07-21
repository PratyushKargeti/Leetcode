class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>S;
        for(int i=0;i<nums1.size();i++)
        {   
            S.insert(nums1.begin(),nums1.begin()+i+1);
            S.insert(nums2.begin(),nums2.begin()+i+1);
            ans.push_back(2*(i+1)-S.size());
            S.clear();
        }
        return ans;   
    }
};