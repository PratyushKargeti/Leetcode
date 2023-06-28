class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int>S;
        for(int i=0;i<arr.size();i++)
        {
            if(S.find(arr[i]*2)!=S.end() || (arr[i]%2==0 && S.find(arr[i]/2)!=S.end()))
                return true;
            S.insert(arr[i]);
        }
        return false;
    }
};