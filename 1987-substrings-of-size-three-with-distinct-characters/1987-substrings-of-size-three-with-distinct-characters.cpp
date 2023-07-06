class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        int count=0;
        if(n<=2) return 0; 
        int i=2;
        while(i<n)
        {
            if(s[i-1]!=s[i] && s[i-2]!=s[i] && s[i-1]!=s[i-2])
                count++;
            i++;
        }
        return count;
    }
};