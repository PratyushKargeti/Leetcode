class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //similar to activity selection problem
        sort(pairs.begin(),pairs.end(),[&](vector<int>a,vector<int>b)
        {
            return a[1]<b[1];  //sort based on ending time
        });
        int cmp=INT_MIN;
        int count=0;
        for(int i=0;i<pairs.size();i++)
        {
            if(pairs[i][0]>cmp)
            {
                cmp=pairs[i][1];
                count++;
            }
        }
        return count;
    }
};