class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        for(int i=0;i<colors.size()-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                ans+=min(neededTime[i],neededTime[i+1]);
                //for next iteration, current iteration's neededTime[i+1] should be maximum as it will become neededTime[i] of next iteration..this is very simple logic
                neededTime[i+1]=max(neededTime[i],neededTime[i+1]);
            }
        }
        return ans;
    }
};