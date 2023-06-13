class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++)
        {
            double val=sqrt(c-(i*i));
            if(val==(int)val)
                return true;
        }
        return false;
    }
};