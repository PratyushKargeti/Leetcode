class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        if(s==goal)
        {
            map<char,int>mp;
            for(int i=0;i<s.size();i++)
            {
                mp[s[i]]++;
                if(mp[s[i]]>1)
                    return true;
            }
            return false;
        }
        int firstind=-1;
        int secondind=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
                if(firstind==-1)
                    firstind=i;
            else if(secondind==-1)      
                    secondind=i;   
            else
                return false;                 
        }
        if(secondind==-1)
            return false;
        return s[firstind]== goal[secondind] && s[secondind]== goal[firstind]; 
        
    }
};