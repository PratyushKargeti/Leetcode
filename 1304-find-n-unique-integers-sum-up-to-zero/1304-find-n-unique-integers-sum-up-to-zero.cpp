class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n%2!=0)
            res.push_back(0);
        while(n>1)
        {
            int k=n/2;
            res.push_back(k);
            res.push_back(-k);
            n-=2;
        }
        return res;
    }
};