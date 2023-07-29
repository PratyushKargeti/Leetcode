class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i; //storing value & positions in hashmap
        }
        for(int i=0;i<operations.size();i++)
        {
            int position_old=m[operations[i][0]]; //retrieving position of element to be replaced
            nums[position_old]=operations[i][1]; //doing replace
            m[operations[i][1]]=position_old; //maintaining new value & its position relationship in hashmap
        }
        return nums;


        //TLE
        // queue<pair<int,int>>q;
        // for(int i=0;i<operations.size();i++)
        // {
        //     q.push(make_pair(operations[i][0],operations[i][1]));
        // }
        // while(!q.empty())
        // {
        //      for(int i=0;i<nums.size();i++)
        //      {
        //          if(q.front().first==nums[i])
        //          {
        //              nums[i]=q.front().second;
        //              q.pop();
        //          }
        //       }
        // }
        // return nums;

    }
};