class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=INT_MIN;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
            int area=min(height[i],height[j])*(j-i);
            if(area>l)
                l=area;
            else if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return l;
    }
};