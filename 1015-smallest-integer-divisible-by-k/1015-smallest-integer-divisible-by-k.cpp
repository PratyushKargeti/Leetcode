class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 0;
        // number of possible values of remainder is 0 to K-1 only (run loop k times only)
        for (int size = 1; size <= k; size++) 
        {
            n = (n * 10 + 1) % k;
            if (n == 0) 
                return size;
        }
        return -1;
    }
};