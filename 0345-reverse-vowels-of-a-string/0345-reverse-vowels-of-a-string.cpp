class Solution {
public:
    string reverseVowels(string s) {
        string bucket="";
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ||s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u')
                bucket+=s[i];
        }
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ||s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u')
                s[i]=bucket[k++];
        }
        return s;
    }
};