class Solution {
public:
// [100,4,200,1,3,2]
// [9,1,4,7,3,-1,0,5,8,-1,6]
// [0]
// [0,0]
// []
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return 1;
        priority_queue<int,vector<int>,greater<int>>pq; //min heap
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        priority_queue<int>pq1; //max heap
        int cnt=1;
        while(!pq.empty())
        {
            int current=pq.top();
            pq.pop();
            if(pq.empty()) break;
            if(pq.top()==current) continue;
            else if(pq.top()==current+1)
            {
                cnt++;
            }
            else
            {  
                pq1.push(cnt); //max heap manages maximum answer at top
                cnt=1;
            }
        }
        pq1.push(cnt); //at the end, value of cnt needs to be pushed
        if(!pq1.empty()) return pq1.top();
        return cnt;
    }
};