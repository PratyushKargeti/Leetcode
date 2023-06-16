class Solution {
public:
    bool isValid(string s){
        if(s.size()==1)
            return false;
        stack<char>St;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(!St.empty() && St.top()=='(')
                    St.pop();
                else
                    return false;
            }
            else if(s[i]=='}')
            {
                if(!St.empty() && St.top()=='{')
                    St.pop();
                else
                    return false;
            }
            else if(s[i]==']')
            {
                if(!St.empty() && St.top()=='[')
                    St.pop();
                else
                    return false;
            }
            else
                St.push(s[i]);
        }
        if(St.size()==0)
            return true;
        return false;
    }
};