class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        int d = 0; //dominant element
        int df = -1; //dominant freq
        for(int i=0;i<n;i++) 
        {
            m[nums[i]]++;
            if (m[nums[i]] > df) 
            {
                d = nums[i];
                df = m[nums[i]];
            }
        }
        // cout<<d<<" "<<df<<endl;
        int l = 0;
        int r = df;
        int elementsatleft,elementsatright;
        for (int i = 0; i < n - 1; i++) 
        {
            if (nums[i] == d) 
            {
                l++;
                r--;
            }
            elementsatleft=i+1;
            elementsatright=n-(i+1);
            if (l*2 > elementsatleft && 2*r > elementsatright) 
                return i;
        }
        return -1;
    }
};