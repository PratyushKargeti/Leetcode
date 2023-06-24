class Solution {
public:
    int minFlips(int a, int b, int c) {
        // int x = (a | b) ^ c;
        // return __builtin_popcount(x) + __builtin_popcount(a & b & x);
        int ans=0;
        while(a!=0 | b!=0 | c!=0)
        {
            int x=a&1; // this operation assigns LSB of a to x
            int y=b&1;
            int z=c&1;
            if(z==1)
            {
                if(x==0 && y==0)
                    ans++;
            }
            else if(z==0)
            {
                ans+= x+y; //lsb of both a and b must be 0 
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};
