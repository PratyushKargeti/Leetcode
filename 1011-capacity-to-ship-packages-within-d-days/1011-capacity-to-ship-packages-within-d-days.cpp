class Solution {
public:
    int f(int cap,vector<int>&weights)
    {
        int sum=0;
        int day=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            if(sum>=cap)
            {
                day++;
                if(sum==cap) sum=0;
                else sum=weights[i];
            }
        }
        if(sum>0 && sum<cap) day++; //if sum less than cap is still left to ship
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(begin(weights),end(weights)); //on any day, minimum capacity of ship must be to carry biggest weight package 
        int high=accumulate(begin(weights),end(weights),0); //on any day, maximum capacity of ship must be carry all packages 
        //search range is sorted, do bs
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(f(mid,weights)<=days)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};