//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        const int prime=101;
        vector <int> search(string pat, string txt)
        {
            int n=txt.length();
            int m=pat.length();
            int th=0;
            int ph=0;
            int h=1;
            for(int i=0;i<m-1;i++)
                h=(h*256)%prime;
            for(int i=0;i<m;i++)
            {
                th=(th*256+txt[i])%prime;
                ph=(ph*256+pat[i])%prime;
            }
            vector<int>ans;
            for(int i=0;i<=n-m;i++)
            {
                if(th==ph)
                {
                    int j;
                    for(j=0;j<m;j++)
                    {
                        if(txt[i+j]!=pat[j])
                            break;
                    }
                    if(j==m)
                        ans.push_back(i+1);
                }
                if(i<n-m)
                {
                    th=((th-txt[i]*h)*256+txt[i+m])%prime;
                    if(th<0)
                        th+=prime;
                }
            }
            if(ans.size()==0)
                return {-1};
            return ans;
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends