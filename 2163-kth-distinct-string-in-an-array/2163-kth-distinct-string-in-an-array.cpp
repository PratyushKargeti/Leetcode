class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int c=0;
        for(int i=0;i<arr.size();i++)
        {
            int flag=0;
            for(int j=0;j<arr.size();j++)
            {
                if(i==j)continue;
                if(arr[i]==arr[j])
                    flag=1;
            }
            cout<<flag<<" ";
            if(flag==0)
            {
                c++;
                if(c==k)
                    return arr[i];
            }
        }
        return "";
    }
};