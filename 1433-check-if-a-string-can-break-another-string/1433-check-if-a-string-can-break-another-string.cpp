class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.size();
        sort(begin(s1),end(s1));
        sort(begin(s2),end(s2));
        int bool1=true;
        for(int i=0;i<n;i++)
        {
            if(!(s1[i]>=s2[i]))
                bool1=false;
        }
        int bool2=true;
        for(int i=0;i<n;i++)
        {
            if(!(s2[i]>=s1[i]))
                bool2=false;
        }
        return bool1 || bool2;
    }
};