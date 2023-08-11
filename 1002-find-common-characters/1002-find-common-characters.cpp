class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        vector<priority_queue<int,vector<int>,greater<int>>>v(26);
        for(string &str:words)
        {
            unordered_map<char,int>m;
            for(char c:str)
            {
                m[c]++;
            }
            for(auto i:m)
            {
                char ch=i.first;
                v[ch-'a'].push(i.second);
            }
        }
        for(int i=0;i<26;i++)
        {
            if(v[i].size()==n) 
            {
                char ch='a'+i;
                int times=v[i].top();
                while(times--)
                {
                    ans.push_back(string(1,ch));
                }
            }
        }
        return ans;
    }
};