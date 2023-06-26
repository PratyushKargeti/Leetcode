class Solution {
public:
    int arrangeCoins(int n) {
        int num=n;
        int count=0;
        for(int i=1;num>0;i++)
        {
            num=num-i;
            count++;
        }
        if(num==0)
            return count;
        else
            return count-1;
    }
};