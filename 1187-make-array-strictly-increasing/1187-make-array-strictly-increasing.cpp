// USING BRUTE FORCE APPROCH TO FIND J INDEX IN ARR2 
// MEMOIZATION
class Solution {
public:
    int dp[2001][2001][2]; 
    int solve(int i,int j,bool flag,int prev,vector<int>&arr1,vector<int>&arr2){
        if(dp[i][j][flag]!=-1) return dp[i][j][flag]; 
        
        if(i==arr1.size()) return 0; 
        
        while(j<arr2.size() && arr2[j]<=prev) j++; 
        if(arr1[i]<=prev && j==arr2.size()) return 2001; 
        
        int take = 2001, nottake= 2001; 
        if(j!=arr2.size())
        take = 1 + solve(i+1,j+1,true,arr2[j],arr1,arr2);
        if(arr1[i]>prev)
        nottake = solve(i+1,j,false,arr1[i],arr1,arr2); 
        return dp[i][j][flag]=min(take,nottake); 
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp,-1,sizeof(dp));
        sort(begin(arr2),end(arr2)); 
        int ans=solve(0,0,false,-1,arr1,arr2); 
        if(ans>arr1.size()) return -1; 
        return ans; 
    }
};