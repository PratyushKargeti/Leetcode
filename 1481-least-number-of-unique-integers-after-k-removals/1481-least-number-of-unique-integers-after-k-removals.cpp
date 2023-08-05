class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        vector<int>freq;
        for(auto i:m)
        {
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        int p=k;
        for(int i=0;i<freq.size();i++)
        {
            p+=freq[i];
            if(p==2*k) return freq.size()-i-1;
            else if(p>2*k) return freq.size()-i;
        }
        return -1;
    }
};