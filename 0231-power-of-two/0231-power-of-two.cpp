class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) 
            return false;
        return ((n & n-1) == 0); 

        // if(n==0) return false;
        //     return (n>0)&&(1073741824%n==0);
    }
};