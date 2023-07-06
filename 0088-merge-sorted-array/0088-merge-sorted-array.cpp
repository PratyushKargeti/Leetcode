class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> b(m+n);
        int i=0,j=0,k=0;
        while(i<=m-1 && j<=n-1)
        {
            if(nums1[i]<nums2[j])
                b[k++]=nums1[i++];
            else
                b[k++]=nums2[j++];
        }
        if(i>m-1)
        {
            while(j<=n-1)
                b[k++]=nums2[j++];
        }
        else
        {
            while(i<=m-1)
                b[k++]=nums1[i++];
        }
        for(int i=0;i<k;i++)
            nums1[i]=b[i];
    }
};