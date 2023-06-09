//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) {
            t[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            int curr = arr[i - 1];
            for (int j = 1; j <= sum; j++) {
                if (curr <= j) {
                    t[i][j] = t[i - 1][j - curr] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends