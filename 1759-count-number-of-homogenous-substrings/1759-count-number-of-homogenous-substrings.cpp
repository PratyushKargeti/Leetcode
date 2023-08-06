class Solution {
public:
// For "a" : 1
// For "aa": 3 (1 + 2)
// For "aaa": 6 (1 + 2 + 3)
// For "aaaa": 10 (1 + 2 + 3 + 4)
// For "aaabbaaaa": 19 (6 + 3 + 10) 
// So, we incease cnt if the previous character is the same (and reset it to 1 otherwise).
    int countHomogenous(string s) {
        int count=0;
        int total=0;
        for(int i=0;i<s.size();i++) 
        {
            if(i==0) count=1; 
            else if(s[i]==s[i-1]) count++;
            else count=1;
            total=(total+count)%1000000007;
        }
        return total;
    }
};
