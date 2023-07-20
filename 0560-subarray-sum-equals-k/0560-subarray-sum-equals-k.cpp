class Solution {
public:
    //we use prefix sum(sum of all elements from 0 to current index) technique, say there are two subarrays which end 
//at index i and they started at different index j1 and j2 (j1<j2<i) and they both had sum k, then there must be two subarrays
//from 0 to j1-1 and 0 to j2-1 whose prefix sum was s-k where s is prefix sum achieved till current index,so the count of subarrays 
//with sum k found till current index i is same as count of s-k prefix sum subarrays
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m; //stores prefix sum and its count in given array
        m[0]=1; //since prefix sum at beginning is 0,we take its count as 1(assume like subarray [] for sum 0) //has significance in further calculation
        int s=0,count=0; //s is prefix sum , count is no of subarrays found so far that have sum k
        for(int i=0;i<nums.size();i++)
        {//At each iteration of the loop, s represents the prefix sum achieved until the current index i.
// The goal is to find subarrays that end at index i whose sum is equal to k.
// To achieve this, we need to find subarrays that start at some index j (where j < i) and end at index i, such that the sum of elements from index j to index i is k.
// We know that the sum of elements from index j to index i is equal to s (the current prefix sum) minus the sum of elements from index j to some previous index t (where t < j). i.e, k=s-(s-k)
// If we have a prefix sum s - k in the map, it means that there exists a subarray whose sum is k,
            s+=nums[i];  //s achieved till current iteration
            count+=m[s-k];  //we look for subarrays with prefix sum as s-k //if s-k is not in map,it is evaluated in 0 ( in C++, if a key is not found in the map, accessing it will return the default value for the value type of the map.)
            m[s]+=1; //increase count of s achieved in current iteration//By incrementing m[s] by 1, we are indicating that we have encountered the prefix sum s one more time.
// This is essential because, as we move forward in the array, the prefix sum can occur multiple times, and each occurrence can contribute to finding subarrays whose sum is equal to k.
        }
        return count;
    }
};
