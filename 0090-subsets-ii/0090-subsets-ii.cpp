class Solution {
public:
    void generateCombinations(vector<int>& arr, vector<int>& ss, vector<vector<int>>& res,int i) 
{
    if(i == arr.size()) 
    {
        res.push_back(ss);
        return;
    }
    else
    {
        ss.push_back(arr[i]);
        generateCombinations(arr, ss, res,i+1);
        ss.pop_back();
        generateCombinations(arr, ss, res,i+1);
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort the input vector
        vector<int> ss;
        vector<vector<int>> res;
        generateCombinations(nums, ss, res, 0);
        // remove duplicate subsets
        sort(res.begin(), res.end()); // sort the result    
        res.erase(unique(res.begin(), res.end()), res.end()); // erase duplicates
        return res;
}

};