class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;
        for(int i=left;i<=right;i++)
        {
            int num=i;
            int flag=0;
            while(num>0)
            {
                int dig=num%10;
                if(dig==0)
                    goto here;
                if(i%dig!=0)
                {
                    flag=1;
                    break;
                }
                num=num/10;
            }
            if(flag==0)
                res.push_back(i);
            here:
               int x=1;
        }   
        return res;
    }
};