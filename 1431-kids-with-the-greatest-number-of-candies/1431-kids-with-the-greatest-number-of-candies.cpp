class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> ans(n);
        auto maxI= max_element(candies.begin(),candies.end());
        for(int i=0;i<n;i++)
        {
            int total =candies[i]+extraCandies;
            if(total>=(*maxI))
            {
                ans[i]=true;
            }
            else
                ans[i]=false;
        }
        return ans;
        
    }
};