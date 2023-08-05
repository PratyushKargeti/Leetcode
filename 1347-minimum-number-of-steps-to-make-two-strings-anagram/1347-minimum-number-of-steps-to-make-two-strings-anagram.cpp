class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        for(char c:s) m[c]++;
        for(char c:t) m[c]--;
        //characters with negative count will be those which are present in t but not in s, absolute sum of all these negative values is answer
        int ans=0;
        for(auto i:m) if(i.second<0) ans+=i.second;
        return abs(ans);
    }
};