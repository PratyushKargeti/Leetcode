class Solution {
public:
    int alternateDigitSum(int n) {
        int num=n;
        string s=to_string(n);
        int length=s.size();
        vector<int>v;
        int x;
        if(length%2==0)
            x=-1;
        else
            x=1;
        while(num>0)
        {
            int rem=num%10;
            rem=rem*x;
            x=-x;
            v.push_back(rem);
            num/=10;
        }
        int sum=0;
        return accumulate(v.begin(),v.end(),sum);
        
    }
};