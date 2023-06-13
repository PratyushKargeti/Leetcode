class Solution {
public:
    int getSum(int a, int b) {
        int x= a&b;  
        int y= a|b;  
        return x+y;
    }
};