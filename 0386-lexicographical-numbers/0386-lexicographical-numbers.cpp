class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>v;
        for(int i=1;i<=n;i++)
            v.push_back(to_string(i));
        sort(v.begin(),v.end(),[](string a,string b){
            return a<b;});
        vector<int>ans;
        for(int i=0;i<v.size();i++)
            ans.push_back(stoi(v[i]));
        return ans;
    }
};