class Solution {
public:
    void reverseString(vector<char>& s) {
        // string ans="";
        // for(int i=s.size()-1;i>=0;i--)
        //     ans+=s[i];
        // s.clear();
        // for(int i=0;i<ans.size();i++)
        //     s.push_back(ans[i]);

        int i=0,j=s.size()-1;
        while(i<j)
            swap(s[i++],s[j--]);
    }
};