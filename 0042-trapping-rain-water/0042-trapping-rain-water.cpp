class Solution {
public:
    int trap(vector<int>& height) {
        //tle
//         int ans=0;
//         for(int i=0;i<height.size();i++)
//         {
//             int maxleft=*max_element(height.begin(),height.begin()+i+1);
//             int maxright=*max_element(height.begin()+i,height.end());
//             cout<<maxleft<<" "<<maxright<<" "<<height[i]<<endl;
            
//             ans+=min(maxleft,maxright)-height[i];
//         }
//         return ans;
        int n=height.size();
        int ans=0;
        vector<int>left(n);
        vector<int>right(n);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        {
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};