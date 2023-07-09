// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         queue<pair<int,int>>q;
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<bool>>visited(m,vector<bool>(n,false));
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==1)
//                 {
//                     q.push({i,j});
//                     visited[i][j]=true;
//                     break;
//                 }
//             }
//             if(!q.empty())
//                 break;
//         }
//         vector<vector<int>>moves{{0,1},{0,-1},{1,0},{-1,0}};
//         int count=0;
//         while(!q.empty())
//         {
//             int fronti=q.front().first;
//             int frontj=q.front().second;
//             int ans=4;
//             q.pop();
//             for(int i=0;i<moves.size();i++)
//             {
//                 int newi=fronti+moves[i][0];
//                 int newj=frontj+moves[i][1];
//                 if(newi<0 || newi>=m || newj<0 || newj>=n || visited[newi][newj]==true || grid[newi][newj]==0)
//                     continue;
//                 else
//                 {
//                     ans--;
//                     q.push({newi,newj});
//                     visited[newi][newj]=true;
//                 }
//             }
//             count+=ans;
//         }
//         return count;
//     }
// };
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    perimeter += 4; // Add 4 sides for each land cell

//When counting the perimeter of the island, we need to account for shared sides between adjacent land cells. Each land cell has four sides, and when two neighboring land cells share a side, we need to deduct one side from each cell to avoid double-counting. 
 //for one it will be left side, for other it will right side which has adjacent cell..so both can be removed from ans
                    // Check left cell
                    if (j > 0 && grid[i][j - 1] == 1)
                        perimeter -= 2; // Deduct 2 sides (left and right)
                   
                    // Check top cell
                    if (i > 0 && grid[i - 1][j] == 1)
                        perimeter -= 2; // Deduct 2 sides (top and bottom)
                }
            }
        }
        return perimeter;
    }
};
