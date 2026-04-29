class Solution {
    int  m, n;
    vector<vector<int>>  dp;
public:
    int rec(vector<vector<int>>& grid, int row, int col){
        if(row>=m || col>=n) return 1e5+1;
        if(row == m-1 && col == n-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=grid[row][col]+min(rec(grid,row+1,col),rec(grid,row,col+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return rec(grid,0,0);
    }
};