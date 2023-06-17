class Solution {
public:

    void countsort(vector<int>&a,int n,int k)
    {
        vector<int>b(n);
        vector<int>count(k+1);

        for(int i=0;i<n;i++)
        {
            count[a[i]]++;
        }
        for(int i=1;i<count.size();i++)
        {
            count[i]=count[i]+count[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            b[--count[a[i]]]=a[i];
        }
        for(int i=0;i<n;i++)
        {
            a[i]=b[i];
        }
    }

    void sortColors(vector<int>& nums) {
        auto it=max_element(nums.begin(),nums.end());
        int k=*it;
        countsort(nums,nums.size(),k);
    }
};