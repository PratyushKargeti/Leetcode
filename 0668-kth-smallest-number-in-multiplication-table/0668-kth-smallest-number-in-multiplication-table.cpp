class Solution {
public:

    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low < high) 
        {
            int mid = low + (high - low) / 2;
            int count = 0;
        // [1 2 3]
        // [2 4 6]
        // [3 6 9]
            for (int i = 1; i <= m; ++i) 
            {
                count += min(mid / i, n); // Count how many elements are less than or equal to mid in each row
            }
        
            if (count < k) 
                low = mid + 1;
            else 
                high = mid;
        }
        return low;
    }
};