class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int r=0,l=0,ans=0;
        for(r=0;r<s.size();r++)
        {
            if(m[s[r]]>0)
                l=max(l,m[s[r]]);
            m[s[r]]=r+1; 
            ans=max(ans,m[s[r]]-l);  
        }
        return ans;
    }
};