class Solution {
public:
    long long func(vector<int>&arr,int mid)
    {
        long long time=0;
        for(int i=0;i<arr.size();i++)
        {
            time+=ceil((double)arr[i]/(double)mid);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(begin(piles),end(piles));
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long reqtime=func(piles,mid);
            if(reqtime<=h)
            {
                high=mid-1; //look for more lesser time on left
            }
            else
            {
                low=mid+1; //look for more bigger time on right
            }
        }
        return low; //after binary search is over, our required minimum answer is always at low , high becomes less than low and goes in invalid region
    }
};

// class Solution {
// public:
//     long long solve(vector<int>& v , int m){
//         long long ans = 0;
//         for (int i=0 ; i<v.size() ; i++){
//             ans += ceil(double(v[i])/double(m));
//         }
//         return ans;
//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
//         int low = 1;
//         int high = *max_element(begin(piles),end(piles));
//         int ans = -1;
//         while (low <= high)
//         {
//             int mid = low+(high-low)/2;
//             if (solve(piles,mid) <= h)
//             {
//                 ans = mid;
//                 high = mid-1;
//             }
//             else
//             {
//                 low = mid+1;
//             }
//         } 
//         return ans;  //same as low at this point 
//     }
// };