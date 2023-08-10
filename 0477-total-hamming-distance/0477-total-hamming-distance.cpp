class Solution {
public:
    int totalHammingDistance(vector<int> &nums){
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++)
        {  
            int ones = 0, zeroes = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] % 2 ==0)
                    zeroes++;
                else if (nums[j] % 1 == 0)
                    ones++;
                nums[j] /= 2;
            }
            if (ones == n || zeroes == n)
                sum += 0;
            else
                sum += (ones * zeroes);
        }
        return sum;
    }
};