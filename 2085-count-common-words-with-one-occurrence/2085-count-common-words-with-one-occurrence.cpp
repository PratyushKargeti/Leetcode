class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        vector<string> v;
        unordered_map<string,int>m;
        for(int i=0;i<words1.size();i++)
        {
            m[words1[i]]++;
        }
        for(auto i:m)
        {
            if(i.second==1)
                v.push_back(i.first);
        }
        for(int i=0;i<words2.size();i++)
        {
            m[words2[i]]--;
        }
        int count=0;
        for(auto i:m)
        {
            if(i.second==0 && find(v.begin(),v.end(),i.first)!=v.end())
                count++;
        }
        return count;
    }
};