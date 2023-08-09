class Solution {
public:

    int findKthNumber(int m, int n, int k) {
        //we can do bs on answer as answer will lie in range [min_ele to max_ele]
        int low = 1, high = m * n;
        //When low and high become equal, it indicates that the search range has narrowed down to a single element. Continuing the search in this case isn't necessary since the desired value has been found.
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
                // it's possible that this mid value is not the actual kth smallest element; there might be multiple elements with the same value as mid.
// If you set high = mid - 1 when count >= k, you might skip over the actual kth smallest element, which could be equal to mid. To ensure that you consider all possible candidates for the kth smallest element, it's better to set high = mid
            
            //count >= k is used to handle cases where there might be multiple occurrences of the same value in the matrix.
            if(count>=k) high=mid; //look for more smaller answer in left part
            else low=mid+1; //look for higher mid in right part
        }
        return low;
    }
};