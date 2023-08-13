class Solution {
public:
    void heapify(vector<int>& nums,int n,int i)
    {
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n && nums[l]>nums[largest])
            largest=l;
        if(r<n && nums[r]>nums[largest])
            largest=r;
        if(largest!=i)
        {
            swap(nums[i],nums[largest]);
            heapify(nums,n,largest);
        }       
    }
    void heapsort(vector<int>& nums,int n)
    {
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(nums,n,i);
        }
        for(int i=n-1;i>=1;i--)
        {
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums;
        heapsort(nums,nums.size());
        return nums;
    }
};