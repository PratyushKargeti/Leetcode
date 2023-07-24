class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long>v;
        for(int i:nums) v.push_back(i);
        for(int i=v.size()-2;i>=0;i--)
        {
            if(v[i]<=v[i+1])
            {    
                v[i]+=v[i+1]; //since nums[i+1] will become new nums[i] after deleting nums[i+1] //effect is same 
                v.erase(v.begin()+i+1);
            }
        }
        return *max_element(v.begin(),v.end());
    }
};