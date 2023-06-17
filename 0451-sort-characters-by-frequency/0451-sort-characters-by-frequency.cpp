class Solution {
    
public:  
    unordered_map<char,int> mp;
    string frequencySort(string s) {
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        sort(s.begin(),s.end(),[this](char a, char b){            
            if (mp[a] == mp[b]) 
                return a < b; // Sort lexicographically if frequencies are the same
            return mp[a]>mp[b]; //else sort by frequency in descending order
        });
        return s;
    }
};