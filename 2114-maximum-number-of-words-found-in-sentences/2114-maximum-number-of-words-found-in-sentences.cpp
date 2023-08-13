class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int w,l=INT_MIN;
        w=1;
        for(string sent : sentences)
        {
            w=1;
            for(int i=0;i<sent.size();i++)
            {
                if(sent[i]==' ' && sent[i+1]!=' ')
                {
                    w++;
                }
            }
            if(w>l)
                l=w;
        }
        return l;
    }
};