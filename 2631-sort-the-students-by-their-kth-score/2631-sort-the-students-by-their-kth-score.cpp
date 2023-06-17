// class Solution {
// public:
//     vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
//         vector<pair<int,int>> v;
//         for(int i=0;i<score.size();i++)
//         {
//             v.push_back({score[i][k],i});
//         }
//         sort(v.begin(),v.end(),greater<pair<int,int>>());
//         vector<vector<int>>ans;
//         for(pair<int,int> i : v)
//         {
//             ans.push_back(score[i.second]);
//         }
//         return ans;
//     }        
// };
    int k1;
     bool comp(vector<int>&a,vector<int>&b)
    {
      return a[k1]>b[k1];  
    }
class Solution {
public:
   
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        k1=k;    
        sort(score.begin(),score.end(),comp);
        return score;
        
    }
};