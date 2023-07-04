class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
    //     auto it1=max_element(nums.begin(),nums.end());
    //     auto it2=min_element(nums.begin(),nums.end());
    //     int maxe=*it1;
    //     int mine=*it2;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(nums[i]!=maxe && nums[i]!=mine)
    //             return nums[i];
    //     }
    //     return -1;
    // }

        sort(nums.begin(), nums.end());
        return nums.size() > 2 ? nums[1] : - 1;
    }

};