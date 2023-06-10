class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //abca //abcababcdc
        unordered_map<char,int>m;
        int l=0,r=0,res=0;
        for(int r=0;r<s.size();r++)
        {
            char curr=s[r];
            if(m[curr]>0) //if s[r] already exist in map
                l=max(l,m[curr]);
            m[curr]=r+1;  // update current s[r]'s value
            res=max(res,m[curr]-l);  //m[s[r]]-l is current substring
        }
        return res;
    }
};