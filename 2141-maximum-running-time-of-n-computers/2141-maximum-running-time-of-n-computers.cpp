class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long long totalcapacity=accumulate(batteries.begin(),batteries.end(),0LL);
        for(int i=batteries.size()- 1; ;i--) 
        {
            long long avgcapacity=totalcapacity/n;
            int biggestbatterycapacity=batteries[i]; //in descending order

            if(biggestbatterycapacity<=avgcapacity) return avgcapacity;//this battery can run all computers for the same amount of time, which is the maximum run time we can achieve in this scenario. Therefore, the function returns the maximum run time, which is avgcapacity.
            
            else//biggest current battery can run for more time than needed. So, we subtract the capacity of the biggest battery from the total capacity 
            {
                totalcapacity-=biggestbatterycapacity;
                n--;//Since we found a battery that can run all computers for more than the average time, we decrease the number of computers n by 1. This way, we account for the fact that one computer will be running on its own battery with more capacity.
            }
        }
    }

    //  long long totalcapacity=accumulate(begin(batteries),end(batteries),0LL);
    //     priority_queue<int>pq(begin(batteries),end(batteries));//max heap
    //     long long avgcapacity=totalcapacity/n;
    //     while(pq.top()>avgcapacity) 
    //     {
    //         totalcapacity-=pq.top();
    //         n--;
    //         avgcapacity=totalcapacity/n;
    //         pq.pop();    
    //     }
    //     return avgcapacity;
};