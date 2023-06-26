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
        cout<<str<<endl;
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
        cout<<j<<endl;
        s.erase(j,1);
        sort(s.begin(),s.end(),[&](char &a,char &b){
            //if(a!=mini-'0' && b!=mini-'0')
                return a<b;
            
        });
        str+=s;
        cout<<str;
        return stoll(str);
        // vector<long long>v;
        // long long n=num;
        // if(num<0)
        //     n=-num;
        // while(n)
        // {
        //     v.push_back(n%10);
        //     n/=10;
        // }
        // if(num<0)
        // {
        //     sort(v.begin(),v.end(),greater<int>());
        //     string ans="";
        //     for(int i=0;i<v.size();i++)
        //     {
        //         ans+=to_string(v[i]);
        //     }
        //     cout<<ans;
        //     long long nnn=stoll(ans);
        //     return -nnn;
        // }
        // long long m;
        // if(v.size()==1)
        //     return v[0];
        // sort(v.begin(),v.end());
        // string ans="";
        // if(v[0]==0)
        // {    
        //     ans+=to_string(v[1]);
        //     for(int i=0;i<v.size();i++)
        //     {
        //         if(i!=1)
        //             ans+=to_string(v[i]);
        //     }
        // }
        // else
        // {
        //     for(int i=0;i<v.size();i++)
        //         ans+=to_string(v[i]);
        // }
        // cout<<ans;
        // m=stoll(ans);
        // return m;
    }
};