class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;i++)
        {
            int flag=0;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0 && i!=1)
                v.push_back(i);
        }
        if(v.size()<2)
            return {-1,-1};
        int mini=INT_MAX;
        int x,y;
        for(int i=0;i<v.size()-1;i++)
        {
            int diff=v[i+1]-v[i];
            if(diff<mini)
            {
                mini=diff;
                x=v[i];
                y=v[i+1];
            }
        }
        return {x,y};
    }
};