class Solution {
public:
    int minNumberOfFrogs(string s) {
        map<char,int>m;
        int frog=0; //keeping count of active frog
        int ans=0;
        for(int i=0;i<s.size();i++)
        {   
            if(s[i]=='c') //active frog starts croaking
                frog++;
            else if(s[i]=='k') //active frog finishes croaking
                frog--;

            m[s[i]]++; //keep count of all occurances of characters

            if(m['c']<m['r'] || m['r']<m['o'] || m['o']<m['a'] ||m['a']<m['k'])
                return -1;  //invalid croak pattern 

            ans=max(ans,frog); //keeping count of max active frog at any time
        }
        if(frog==0) return ans; //if all frogs have finished croaking
        else return -1; //invalid croak pattern
    }
};