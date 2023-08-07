// class Solution {
// public:
//     vector<int> findRightInterval(vector<vector<int>>& intervals) {
//         vector<int>ans;
//         unordered_map<int,int>m;
//         for(int i=0;i<intervals.size();i++)
//         {
//             m[intervals[i][0]]=i;
//         }
//         for(int i=0;i<intervals.size();i++)
//         {
//             int target=intervals[i][1];
//             int low=target;
//             int high=1000001;
//             while(low<=high)
//             {
//                 int mid=low+(high-low)/2;
//                 if(m.count(mid) && mid>=target)
//                 {
//                     high=mid-1;
//                 }
//                 else
//                 {
//                     low=mid+1;
//                 }
//             }
//             ans.push_back(m.count(low) ? m[low] : -1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        map<int, int> m; // Using a map to keep the sorted order
        
        // Create a map of start points to their indices
        for (int i = 0; i < intervals.size(); i++) 
        {
            m[intervals[i][0]] = i;
        }
        
        // Iterate through each interval and find the right interval
        for (int i = 0; i < intervals.size(); i++) 
        { 
            int target=intervals[i][1];
             //Find smallest interval with start >= target
            auto it = m.lower_bound(target);
            if(it!=m.end()) ans.push_back(it->second);
            else  ans.push_back(-1);
        }
        return ans;
    }
};
