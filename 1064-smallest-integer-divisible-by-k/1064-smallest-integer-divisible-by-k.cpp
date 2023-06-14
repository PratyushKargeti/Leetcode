class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 0;
        for (int ln = 1; ln <= k; ln++) 
        {
            n = (n * 10 + 1) % k;
            if (n == 0) 
                return ln;
        }
        return -1;
    }
};