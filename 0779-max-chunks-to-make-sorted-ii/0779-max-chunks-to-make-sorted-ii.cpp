class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int curr_max=INT_MIN;
        int count=1;
        for(int i=0; i<v.size()-1; i++)
        {
            curr_max=max(curr_max, v[i]); //find max element upto current
            int curr_rightmin=*min_element(v.begin()+(i+1), v.end());//find min element in right side of current
            if(curr_rightmin >= curr_max) 
              count++;
        }
        return count;
    }
};