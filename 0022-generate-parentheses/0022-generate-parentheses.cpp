class Solution {
public:
    void combinations(int obcount,int cbcount,string s,vector<string> &res)
    {
        if(obcount==0 && cbcount==0)
        {
            res.push_back(s);
            return;
        }
        if(obcount!=0)
            combinations(obcount-1,cbcount,s+'(',res);
        if(obcount<cbcount)
            combinations(obcount,cbcount-1,s+')',res);
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> res;
        int obcount=n;
        int cbcount=n;
        combinations(obcount,cbcount,s,res);
        return res;
    }
};