class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        while(x)
        {
            long long dig=x%10;
            rev=rev*10+dig;
            x/=10;
        }
        if(rev>INT_MAX || rev<INT_MIN)
            return 0;
        return rev;
    }
};