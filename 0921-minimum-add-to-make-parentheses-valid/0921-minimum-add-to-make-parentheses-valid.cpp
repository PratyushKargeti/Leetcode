class Solution {
public:
    int minAddToMakeValid(string s) {
        int moves=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') count++;
            else count--;
            if(count<0) //at this point we got one ')' more than '(' so we need to add '(' before '(' which is one move
            {
                moves++;  // ()) ---> ()()
                count=0; //hence we balanced the string again
            }
        }
        moves+=count; //count will store additional moves of inserting ')' at last in order to balance excess of '('  // (((( ---->(((())))
        return moves;
    }
};