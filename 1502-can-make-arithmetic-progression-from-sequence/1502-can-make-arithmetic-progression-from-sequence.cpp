class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int x=arr[1]-arr[0];
        int flag=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(!((arr[i+1]-arr[i])==x))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            return 1;
        return 0;
        //return flag;
    }
};