class Solution {
public:
    int count=0;
    void merge(vector<int>&nums,int low,int mid,int high)
    {
        int i=low,j=mid+1,k=low;
        int b[high+1];
        while(i<=mid && j<=high)
        {
            if(nums[i]<nums[j])
                b[k++]=nums[i++];
            else
                b[k++]=nums[j++];
        }
        if(i>mid)
        {
            while(j<=high)
                b[k++]=nums[j++];
        }
        else
        {
            while(i<=mid)
                b[k++]=nums[i++];
        }
        for(int i=low;i<=high;i++)
        {
            nums[i]=b[i];
        }
    }
    void countpairs(vector<int>&nums,int low,int mid,int high)
    {
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && (long long)nums[i]>(long long)2*nums[j])
                j++;
            count+=j-(mid+1);
        }
    }
    void mergesort(vector<int>&nums,int low,int high)
    {
        if(low<high)
        {
            int mid=low+(high-low)/2;
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);
            countpairs(nums,low,mid,high);
            merge(nums,low,mid,high);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return count;
    }
};