class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> secondary;
        // set<int>S;
        // vector<int> ans;
        // S.insert(nums1.begin(),nums1.end());
        // for(int i: S)
        // {
        //     secondary.push_back(i);
        // }
        // for(int i=0;i<secondary.size();i++)
        // {
        //     for(int j=0;j<nums2.size();j++)
        //     {
        //         if(secondary[i]==nums2[j])
        //         {
        //             ans.push_back(secondary[i]);
        //             break;
        //         }
        //     }
        // }
        // return ans;
        vector<int> ans;
        int n=nums1.size();
        int m=nums2.size();
        sort(nums1.begin(),nums1.end()); //1,1,2,2
        sort(nums2.begin(),nums2.end());//2,2
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(nums1[i]==nums2[j])
            {
                if(ans.empty() || ans.back()!=nums1[i])
                    ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        return ans;
    }    
};