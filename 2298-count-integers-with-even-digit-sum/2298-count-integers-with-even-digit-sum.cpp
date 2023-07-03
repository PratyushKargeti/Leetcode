class Solution {
public:
    int countEven(int num) {
        int c=0;
        for(int i=1;i<=num;i++)
        {
            int numb=i;
            int sum=0;
            while(numb>0)
            {
                sum+=numb%10;
                numb/=10;
            }
            if((sum&1)==0) //put in brackets as precedence of == > &
            {
                c++;
            }
        }
        return c;
    }
};