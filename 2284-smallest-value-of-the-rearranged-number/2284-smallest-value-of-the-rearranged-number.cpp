class Solution {
public:
    long long smallestNumber(long long num) {
        string s=to_string(num);
        if(s[0]=='-')
        {
            sort(s.begin(),s.end(),[&](char &a,char &b){
                return a>b;
            });
            return -(stoll(s));
        }
        if(num==0)
            return 0;
        string str="";
        int mini=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>48 && s[i]<=57)
            {
                mini=min(s[i]-'0',mini);
            }
        }
        str+=to_string(mini);
        //cout<<str<<endl;
        int j;
        for(int i=0;i<s.size();i++)
        {
            int x=s[i]-'0';
            if(x==mini)
            {
                j=i;
                break;
            }
        }
        //cout<<j<<endl;
        s.erase(j,1);
        sort(s.begin(),s.end(),[&](char &a,char &b){
                return a<b;
        });
        str+=s;
        //cout<<str;
        return stoll(str);
    }
};