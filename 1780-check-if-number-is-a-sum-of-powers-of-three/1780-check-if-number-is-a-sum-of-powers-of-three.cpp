class Solution {
public:
    bool numberToBase(int number, int base) {
        vector<int>digits(32);  // Maximum number of digits for base 2 (binary) representation of a 32-bit integer
        int numDigits = 0;
        if(number == 0) 
        {
            digits[numDigits++] = 0;
        } 
        else 
        {
            while(number!=0) 
            {
                int remainder = number % base;
                digits[numDigits++] = remainder;
                number /= base;
            }
        }
        for(int i=numDigits-1; i>=0; i--) 
        {
            if(digits[i]==2) return false;
        }
        return true;  
    }
    //to express a number as sum of power of 3, its ternary representation must not have 2 
    bool checkPowersOfThree(int n) {
        return numberToBase(n,3);
    }
};