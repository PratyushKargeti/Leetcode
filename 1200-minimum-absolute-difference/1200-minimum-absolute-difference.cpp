class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mind=INT_MAX;
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<arr.size()-1;i++)
        {
            mind=min(mind,arr[i+1]-arr[i]);
        }
        cout<<mind<<endl;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]-arr[i]==mind)
                ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};