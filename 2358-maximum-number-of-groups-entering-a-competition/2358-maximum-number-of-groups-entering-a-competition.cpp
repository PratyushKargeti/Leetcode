class Solution {
public:
//Let the marks of students be [a1, a2, a3, a4, a5, a6] in the sorted order. If we form the groups in the following format the required condition will hold:

// (a1)
// (a2, a3)
// (a4, a5, a6)
// Arranging in the above pattern always works because:

// (a2 >= a1) and (a3 >= a1) therefore (a2+a3) > a1
// (a4 >= a3), (a5 >= a3) and (a6 >= a3) therefore (a4+a5+a6) > (a2+a3)
//So we need to find out the maximum result k that
// 1 + 2 + ... + k <= n

// Prove:
// Sort groups by size,
// so the first group has size at least 1
// so the second group has size at least 2
// kth group has size at least k...
//Find a number K between 1 to n such that sum of first K natural numbers is less than or equal to n.

    bool possible(int k,vector<int>&grades,int n)
    {
        long long sum=(long long)k*(k+1)/2;
        return sum<=n;
    }
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        int low=1;
        int high=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(mid,grades,n))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;
    }
};