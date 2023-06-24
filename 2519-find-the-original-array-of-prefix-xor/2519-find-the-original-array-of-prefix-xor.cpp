class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>arr(pref.size());
        arr[0]=pref[0];  //a
        for(int i=1;i<pref.size();i++)
        {
            //arr[i] ^ pref[i-1] = pref[i]
            //x^a=b  => x= a^b
            arr[i]=pref[i-1]^pref[i];
        }
        return arr;
    }
};