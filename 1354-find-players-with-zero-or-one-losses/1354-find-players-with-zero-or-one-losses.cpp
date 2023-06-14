class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int,int>m;
        for(int i=0;i<mat.size();i++)
        {
            m[mat[i][1]]++;
        }
        vector<int>v1;
        vector<int>v2;
        for(auto i:m)
        {
            if(i.second==1)
                v2.push_back(i.first);
        }
        for(int i=0;i<mat.size();i++)
        {
            if(m.count(mat[i][0])==0)
                v1.push_back(mat[i][0]);
            else if(m.count(mat[i][1])==0)
                v1.push_back(mat[i][1]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        v1.erase(unique(v1.begin(),v1.end()),v1.end());
        v2.erase(unique(v2.begin(),v2.end()),v2.end());
        return {v1,v2};
    }
};