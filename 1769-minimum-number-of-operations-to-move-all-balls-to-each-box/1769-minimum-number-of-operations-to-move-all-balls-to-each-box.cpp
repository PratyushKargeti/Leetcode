class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            int sum=0;
            for(int j=0;j<s.size();j++)
            {
                if(j!=i)
                {
                    if(s[j]=='1')
                    {
                        sum+=abs(j-i);
                    }
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};