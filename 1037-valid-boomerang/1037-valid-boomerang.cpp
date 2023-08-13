class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1=points[0][0];
        int y1=points[0][1];
        int x2=points[1][0];
        int y2=points[1][1];
        int x3=points[2][0];
        int y3=points[2][1];
        if((x1==x2 && y1==y2) || (x2==x3 && y2==y3) || (x1==x3 && y1==y3))
            return false;
        if(x2-x1==0 || x3-x2==0)
        {
            if(x1==x2 && x2==x3)
                return false;
            else
                return true;
        }
        else
        {
            double s1=double((y2-y1))/(x2-x1);
            double s2=double((y3-y2))/(x3-x2);
            if(s1==s2)
                return false;
            else    
                return true;
        }
    }
};