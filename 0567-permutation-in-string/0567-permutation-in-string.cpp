class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        sort(begin(s1),end(s1));
        for(int i=0;i<=s2.length()-s1.length();i++)
        {
            string str=s2.substr(i,s1.length());
            sort(begin(str),end(str));
            if(str==s1) return true;
        }
        return false;
    }
};