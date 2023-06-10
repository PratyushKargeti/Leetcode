class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int leftmax=INT_MIN;
        int res=0;
        for(int i=0;i<n;i++)
        {
		     leftmax=max(leftmax,arr[i]);
             if(leftmax==i)
                 res++;
        }
        return res;
    }
};