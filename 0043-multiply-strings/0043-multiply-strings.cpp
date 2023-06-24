class Solution {
public: 
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string ans(n + m, '0');
        for(int i = n - 1; i>=0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                //ans[i+j+1] is current carry
                int p=(num1[i]-'0')*(num2[j]-'0')+(ans[i+j+1]-'0');
                ans[i+j+1] = p % 10 + '0'; //current value digit in ans
                ans[i+j] += p / 10 ; //new carry for next multiplication
            }
        }
        for(int i = 0; i < m + n; i++)
        {
            if(ans[i] !='0')
                return ans.substr(i);
        }
        return "0";
    }
};