class Solution {
public:
    //same as 1347(first part of this)
    //find count of characters which are present in t but not in s
    //find count of characters which are present in s but not in t
    //add both
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        for(char c:s)m[c]++;
        for(char c:t)m[c]--;
        int res1=0;
        for(auto i:m) if(i.second<0) res1+=i.second;
        m.clear();
        for(char c:t)m[c]++;
        for(char c:s)m[c]--;
        int res2=0;
        for(auto i:m) if(i.second<0) res2+=i.second;
        return abs(res1)+abs(res2);
    }
};