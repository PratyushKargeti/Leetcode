class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            int key=(i+1)*(arr.size()-i);
            int times=(key+1)/2;
            sum+=times*arr[i];
        }
        return sum;
    }
};