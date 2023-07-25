class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //Linear Soln O(n)
        // for(int i=0;i<arr.size()-1;i++)
        // {
        //     if(arr[i]>=arr[i+1])
        //         return i;
        // }
        // return -1;
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid!=0 && mid!=n-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid+1]>arr[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
};