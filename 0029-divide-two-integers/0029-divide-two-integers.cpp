class Solution {
public:
    long double divide(int dividend, int divisor) {
        long double ans=(long double)dividend/divisor;
        if(ans>0)
            ans=floor(ans);
        else
            ans=ceil(ans);
        if(ans>INT_MAX)
            return (pow(2,31)-1);
        else if(ans<INT_MIN)
            return (-pow(2,31));
        else
            return ans;
    }
};