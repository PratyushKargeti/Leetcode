class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int mini_x=intervals[0][0];
        int mini_y=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=mini_y)
            {
                mini_x=min(mini_x,intervals[i][0]);
                mini_y=max(mini_y,intervals[i][1]);
            }
            else
            {
                ans.push_back({mini_x,mini_y});
                mini_x=intervals[i][0];
                mini_y=intervals[i][1];
            }
        }
        ans.push_back({mini_x,mini_y});
        return ans;
    }
};