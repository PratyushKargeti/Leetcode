class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0,j=0,k=0;
        while(i<=word1.size()-1 && j<=word2.size()-1)
        {
            ans+=word1[i++];
            ans+=word2[j++];
        }
        if(i>word1.size()-1)
        {
            while(j<=word2.size()-1)
                ans+=word2[j++];
        }
        else
        {
            while(i<=word1.size()-1)
                ans+=word1[i++];
        }
        return ans;
    }
};