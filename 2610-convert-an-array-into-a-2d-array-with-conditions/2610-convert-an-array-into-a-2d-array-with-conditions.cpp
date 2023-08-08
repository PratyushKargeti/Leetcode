class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        //there will be 'max freq of any element' no. of rows in final 2d array
        vector<vector<int>> ans;
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++) m[nums[i]]++; //taking freq
        int maxi=0; 
        for(auto x:m)
        {
            if(x.second>maxi) maxi=x.second; //finding max freq
        }
        
        for(int i=0;i<maxi;i++) //run loop max freq times for max freq rows
        {
            int flag=0; 
            vector<int> row;
            for(auto &x:m)
            {
                if(x.second>0)
                {
                    flag=1; //elements need to be added in current row
                    row.push_back(x.first);
                    x.second--; //decrease their count for current row
                }
            }
            if(flag==0) return ans; //no elements need to be added to current row
            
            ans.push_back(row);
        }
        return ans;
    }
};