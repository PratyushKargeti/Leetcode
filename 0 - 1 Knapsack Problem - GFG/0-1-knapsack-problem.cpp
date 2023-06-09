//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> t(n+1,vector<int>(W+1,0));
        for(int i=1;i<=n;i++)
        {
            int p=val[i-1];
            int w=wt[i-1];
            for(int j=1;j<=W;j++)
            {
                if(w<=j)
                {
                    t[i][j]=max(p+t[i-1][j-w], t[i-1][j]);
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends