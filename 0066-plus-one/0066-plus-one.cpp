class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]+1>9)
            {
                digits[i]=0;
            }
            else
            {
                digits[i]=digits[i]+1;
                break;
            }
        }
        if(i<0)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};