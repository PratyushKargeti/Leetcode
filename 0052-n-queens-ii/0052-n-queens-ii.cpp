class Solution {
public:
    int ans;
    bool canPlace(int currRow, vector<int>& a) {
        for(int row = 0; row < currRow; row++)
            if(a[currRow] == a[row] || abs(a[currRow]-a[row]) == currRow-row) 
                return false;
        return true;
    }
    
    void dfs(int i, int n, vector<int>& a, vector<string>& v) {
        if(i == n){
            ans++;
            return;
        }
        for(int col = 0; col < n; col++)
        {
            a[i] = col;
            if(canPlace(i, a))
            {
                v[i][col] = 'Q';
                dfs(i+1, n, a, v);
                v[i][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> a(n);
        vector<string> v(n);        
        for(int i = 0; i < n; i++) 
            v[i] = string(n, '.');
        
        dfs(0, n, a, v);
        return ans;
    }
};
