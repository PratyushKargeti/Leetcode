class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0,curr=0;
        for(int i=0;i<k;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            curr++;
        }
        ans = max(ans,curr);
        for(int i=k;i<s.length();i++)
        {
            if(( s[i]=='a'  ||  s[i]=='e'  ||  s[i]=='i'  ||  s[i]=='o'  ||  s[i]=='u' )  &&  (  s[i-k]!='a'  &&  s[i-k]!='e'  &&  s[i-k]!='i'  &&  s[i-k]!='o'  &&  s[i-k]!='u' ))
            curr++;// checks if the character "k" positions to the left of it (i.e. at index "i-k") is not a vowel. If this condition is true, it increments the "curr" variable by 1, since we have found a new substring with a vowel in its first position.
            else if((s[i]!='a' && s[i]!='e' && s[i]!='i'  &&  s[i]!='o'  &&  s[i]!='u')  &&  (s[i-k]=='a'  ||  s[i-k]=='e'  ||  s[i-k]=='i'  ||  s[i-k]=='o'  ||  s[i-k]=='u'))
            curr--;
            ans = max(ans,curr);
        }
        return ans;
    }
};