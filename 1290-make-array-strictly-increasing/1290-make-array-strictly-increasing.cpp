class Solution {
public:
    int solve(int i,int j,int n,int m,int prev,vector<vector<int>> &dp,vector<int> &arr1,vector<int> &arr2){
        if(i==n)
            return 0;
        j = upper_bound(arr2.begin()+j,arr2.end(),prev)-arr2.begin(); //index of min elem > prev
        if(dp[i][j] != -1)
            return dp[i][j];    
        if(j>=m && prev>=arr1[i])
            return 2001; // returning value greater than arr1.length,i.e,2000
        int take = 2001,nottake = 2001;
        if(j<m)
            take = 1 + solve(i+1,j+1,n,m,arr2[j],dp,arr1,arr2);
        if(prev<arr1[i])
            nottake = solve(i+1,j,n,m,arr1[i],dp,arr1,arr2);
        return dp[i][j] = min(take,nottake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m =arr2.size();
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        sort(arr2.begin(),arr2.end());
        int ans= solve(0,0,n,m,-1,dp,arr1,arr2);
        if(ans>n)
            return -1;
        return ans;
    }
};