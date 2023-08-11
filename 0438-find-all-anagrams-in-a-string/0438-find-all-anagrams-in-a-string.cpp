class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenp = p.length();
        int lens = s.length();
        if(lenp>lens) return {};
        vector<int> ans;
        unordered_map<char, int> mp, ms;
        for(char c : p) mp[c]++;    
        
        for (int i=0;i<lenp;i++)  ms[s[i]]++;
        
        if (ms == mp) ans.push_back(0);
        
        for (int i=lenp;i<lens;i++) 
        {
            ms[s[i-lenp]]--;  // Remove leftmost character from window
            
            //if leftmost character no longer present in current window
            if(ms[s[i-lenp]]==0) 
            {
                ms.erase(s[i-lenp]); //remove it from current window map
            }
            
            ms[s[i]]++;  // Add the current character to the window

            //if frequency of elements in current window is equal to that in pattern p, then store starting index of current window in ans vector
            if (ms == mp) 
            {
                ans.push_back(i-lenp+1);
            }
        }
        return ans;
    }
};