class Solution {
    int  m ,n;
    vector<vector<int>> dp;
public:
    int rec(vector<vector<int>>& obstacleGrid, int row, int col){
        if(row >  m  || col >n) return 0;
        if(row == m-1 && col == n-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int ans = 0;
        if(row+1<m && !obstacleGrid[row+1][col]) ans  =rec(obstacleGrid,row+1,col);
        if(col+1<n && !obstacleGrid[row][col+1]) ans  +=rec(obstacleGrid,row,col+1);
        return dp[row][col] = ans;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] || obstacleGrid[0][0] ) return 0;
        dp.assign(m+1,vector<int>(n+1,-1));
        return rec(obstacleGrid,0,0);
    }
};