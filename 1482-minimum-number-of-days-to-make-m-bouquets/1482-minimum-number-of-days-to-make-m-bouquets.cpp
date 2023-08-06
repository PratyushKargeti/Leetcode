class Solution {
public:
    bool possible(int day,vector<int>&arr,int m,int k)
    {
        int cnt=0;//keeps count of adjacent flowers
        int b=0; //keeps count of no. of bouquets possible for given day
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=day) cnt++;
            else
            {   
                b+=cnt/k;
                cnt=0;
            }
        }
        b+=cnt/k;
        if(b<m) return false; //if possible bouquests less than required one,false
        return true;
    }
    //answer will be in btw minimum and maximum element in array,so apply binary search //noting that search space is actually sorted 
    int minDays(vector<int>& arr, int m, int k) {
        long long tot=(long long)m*k;
        if(arr.size()<tot) return -1; //required flowers more than size(bad case)
        int mini=*min_element(begin(arr),end(arr));
        int maxi=*max_element(begin(arr),end(arr));
        int low=mini;
        int high=maxi;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(mid,arr,m,k))
            {
                high=mid-1; //look for more minimum day at left part
            }
            else
            {
                low=mid+1; //look for higher possible day in right part
            }
        }
        return low;
    }
};