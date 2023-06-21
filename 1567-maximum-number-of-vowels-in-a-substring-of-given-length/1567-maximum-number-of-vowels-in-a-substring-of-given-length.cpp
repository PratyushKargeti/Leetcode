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
            else if((s[i]!='a' && s[i]!='e' && s[i]!='i'  &&  s[i]!='o'  &&  s[i]!='u')  &&  (s[i-k]=='a'  ||  s[i-k]=='e'  ||  s[i-k]=='i'  ||  s[i-k]=='o'  ||  s[i-k]=='u'))//If this condition is true, it means that the substring at the current position does not have a vowel in its first position, but the substring at the position k positions to the left had a vowel in its first position. In this case, curr is decremented by 1, indicating that we have found a substring where a vowel is removed from its first position. After each iteration of the second loop, update ans to hold the maximum value between ans and curr. This ensures that ans always holds the maximum count of vowels found so far in any substring of length k.
            curr--;
            ans = max(ans,curr);
        }
        return ans;
    }
};