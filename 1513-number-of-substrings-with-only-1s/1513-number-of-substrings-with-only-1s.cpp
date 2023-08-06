class Solution {
public:
//same as 1759.
//logic
// For "a" : 1
// For "aa": 3 (1 + 2)
// For "aaa": 6 (1 + 2 + 3)
// For "aaaa": 10 (1 + 2 + 3 + 4)
// For "aaabbaaaa": 19 (6 + 3 + 10) 
// So, we incease cnt if the previous character is the same (and reset it to 1 otherwise).
    int numSub(string s) {
        int total=0;
        int count=0;
        for(int i=0; i<s.size(); i++) 
        { 
            if(i==0 && s[i]=='1') count=1;
            else if(i==0 && s[i]=='0') count=0;
            else if(s[i]=='1')
            {
                if(s[i]==s[i-1]) count++; 
                else count=1;  //new starting of ones        
            }
            else if(s[i]=='0') count=0; //reset count 
            
            total=(total+count)%1000000007;
        }
        return total;
    }
};