class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]+nums[j]==target)
        //             return {i,j};
        //     }
        // }
        // return {-1,-1};

        // Iterate through the array and check for complements
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement=target-nums[i];
             //element will exist in array if it is present as key in map
             //If you call m.count(key) on an std::unordered_map named m, it will return the number of elements with the specified key in m. The count will be either 0 (if the key does not exist in the map) or 1 (if the key exists).
             // If the complement exists in the map, return the indices
            if(m.count(complement)>0)
                return {i, m[complement]};    
            // Add the current number and its index to the map
            m[nums[i]]=i;
       }
       return {-1,-1};
    }
};