class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long>S;
        S.insert(1);
        long long curr; //current ugly
        for(int i=0;i<n;i++)
        {
            curr=*S.begin();
            S.erase(curr);
            S.insert(curr*2);
            S.insert(curr*3);
            S.insert(curr*5);
        }
        return curr; //current ugly is nth ugly
    }
};