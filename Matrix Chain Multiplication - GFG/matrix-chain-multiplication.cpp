//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        //int l=sizeof(arr)/sizeof(arr[0]);
        int n=N-1;
        vector<vector<int>> t(n+1,vector<int>(n+1,0));
        for(int l=2;l<=n;l++)
        {
            for(int i=1;i<=n-l+1;i++)
            {
                int j=i+l-1;
                t[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int q=t[i][k]+t[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    if(q<t[i][j])
                        t[i][j]=q;
                }
            }
        }
        return t[1][n];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends