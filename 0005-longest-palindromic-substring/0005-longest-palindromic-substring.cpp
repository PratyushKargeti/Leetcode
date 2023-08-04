class Solution {
public:
    string longestPalindrome(string s) {
        //Because problem wants longest palindrome, we can start by checking  longest substrings and iterate toward the shorter-length substrings. First time we find palindrome substring, it is answer
        int n=s.size();
        for(int len = n; len>0; len--)  //size decreases from n to 1
        {
            for(int start=0; start<n-len+1; start++) //start pos index from 0 to n-1
            {
                if(palin(start,start+len,s)) 
                {
                    return s.substr(start,len);
                }
            }
        }
        return "";
    }

    bool palin(int i, int j, string& s) {
        int left = i;
        int right = j-1;
        while(left<right) 
        {
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

//tle
    // string longestPalindrome(string s) {
    //     int n=s.size();
    //     string ans="";
    //     cout<<s.size()<<ans.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i;j<n;j++)
    //         {
    //             string sub=s.substr(i,j-i+1);
    //             if(palin(sub) && sub.size()>ans.size())
    //             {
    //                 ans=sub;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    // bool palin(string &s){ 
    //     if(s.size()==0) return false;
    //     int i=0;
    //     int j=s.size()-1;
    //     while(i<=j)
    //     {
    //         if(s[i]!=s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
};