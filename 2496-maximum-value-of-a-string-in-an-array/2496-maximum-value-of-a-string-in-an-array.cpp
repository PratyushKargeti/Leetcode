class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int l=0;
        for(int i=0;i<strs.size();i++)
        {
            int flag=1,val;
            for(int j=0;j<strs[i].size();j++)
            {
                if(!(strs[i][j]>=48 && strs[i][j]<=57))
                {
                    val=strs[i].size();
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                val=stoi(strs[i]); //argument of stoi has to be "integer" else error
            l=max(val,l);
        }   
        return l;
    }
};