class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array in ascending order
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) 
        {
            if (nums[i] > 0)
                break; // No more possible triplets since the remaining elements are greater than zero
            
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue; // Skip duplicates //no need to check for first element obviously
            //now simple two pointer 
            int left = i + 1;
            int right = n - 1;
            while (left < right) 
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) 
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--; 
                    //duplicates will be seen for these new positions of left and right compared with previuos ones
                    while(left < right && nums[left] == nums[left - 1])
                        left++; // Skip duplicates
                    while(left < right && nums[right] == nums[right + 1])
                        right--; // Skip duplicates
                }
                else if (sum < 0) 
                    left++;
                else 
                    right--;
            }
        }
        return ans;
    }        
};
