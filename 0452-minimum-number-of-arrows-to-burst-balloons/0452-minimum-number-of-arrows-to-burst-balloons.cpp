class Solution {
public:
int findMinArrowShots(vector<vector<int>>& points) {
    vector<pair<int, int>> b;
    for (int i = 0; i < points.size(); i++) {
        int s = points[i][0];
        int e = points[i][1];
        b.push_back(make_pair(e, s));
    }
    sort(b.begin(), b.end());
    int count = 0;
    int compare = INT_MIN;
    int flag=0;
    for (int i = 0; i < points.size(); i++) 
    {
        if(b[i].second==INT_MIN && compare==INT_MIN && flag==0)
        {
                count++;
                flag=1;
        }
        if (b[i].second > compare) 
        {
            compare = b[i].first;
            count++;
        }
    }
    return count;
}
};