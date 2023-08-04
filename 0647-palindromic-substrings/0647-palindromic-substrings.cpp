class Solution {
public:
    bool palin(string& s){ 
        if(s.size()==0) return false;
        int i=0;
        int j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.length();
        vector<string>substrings;
        for(int i=0;i<n;i++) 
        {
            for(int j=i+1;j<=n;j++) 
            {
                substrings.push_back(s.substr(i,j-i));
            }
        }
        int count=0;
        for(string str:substrings) 
        {
            if(palin(str))
                count++;
        }
        return count;
    }
};