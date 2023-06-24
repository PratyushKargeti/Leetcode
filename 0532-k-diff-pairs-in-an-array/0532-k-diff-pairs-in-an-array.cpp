class Solution {
public:
    int findPairs(vector<int>& nums, int k) { 
            unordered_map<int,int>m;
            int ans=0;
            for(int i=0;i<nums.size();i++)
            {
                m[nums[i]]++;
            }
            for(auto i:m)
            {
                if(k>0 && m.count(i.first-k)>0)
                    ans++;
                else if(k==0 && i.second>1)
                    ans++;
            }
            return ans;
    }
//      //   brute force (not affective)
//         int count=0;
//         vector<vector<int>>v;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(i!=j)
//                 {
//                     if(abs(nums[i]-nums[j])==k)
//                     {
//                         count++;   
//                         v.push_back({min(nums[i],nums[j]),max(nums[i],nums[j])});
//                     }
//                 }
//             }
//         }   
//         //// for(int i=0;i<v.size();i++)
//         // {
//         //     for(int j=0;j<v[0].size();j++)
//         //         cout<<v[i][j]<<" ";
//         //     cout<<endl;
//         // }//
//         sort(v.begin(),v.end());
//       //  // cout<<"------\n";//
//         v.erase(unique(v.begin(),v.end()),v.end());
// //// for(int i=0;i<v.size();i++)
//         // {
//         //     for(int j=0;j<v[0].size();j++)
//         //         cout<<v[i][j]<<" ";
//         //     cout<<endl;
//       //  // }
//         return v.size();
};