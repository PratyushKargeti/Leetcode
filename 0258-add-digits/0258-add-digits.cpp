class Solution {
public:
    int addDigits(int num) {
        num--;
        return num%9+1;
    }

};