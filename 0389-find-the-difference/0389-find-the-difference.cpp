class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0,sum2=0;
        for(int i=0;i<s.size();i++)
        {
            sum1+=s[i]-'a';
        }
        cout<<sum1;
        for(int i=0;i<t.size();i++)
        {
            sum2+=t[i]-'a';
        }
        cout<<"\n"<<sum2;
        return 'a'+(sum2-sum1);
    }
};