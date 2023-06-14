class Solution {
public:
    int reverse(int x)
    {
        int rev=0;
        while(x>0)
        {
            int rem=x%10;
            rev=rev*10+rem;
            x/=10;
        }
        return rev;
    }
    bool sumOfNumberAndReverse(int n) {
        for(int i=n/2;i<=n;i++)
        {
            int x=i;
            int y=reverse(x);
            if(x+y==n)
                return true;
        }
        return false;
    }
};