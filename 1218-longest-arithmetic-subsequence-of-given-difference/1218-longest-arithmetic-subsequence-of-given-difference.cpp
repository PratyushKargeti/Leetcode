class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int>m;
        int answer=1;
        // for(int i=0;i<arr.size();i++)
        // {
        //     m[arr[i]]=1+m[arr[i]-difference];
        //     answer=max(answer,m[arr[i]]);
        // }
        //The Intuition is to iterate through the array and uses dynamic programming to find the length of the longest subsequence with a given difference. It maintains a map to store the maximum length of subsequences ending at each number. By leveraging this map and updating the maximum length seen so far, it efficiently computes the desired result.
        for(int a:arr)
        {
            m[a]=m[a-difference]+1;
            answer=max(answer,m[a]);
        }
        return answer;
    }
};