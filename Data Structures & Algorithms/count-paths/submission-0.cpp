class Solution {
    int  M,N;
    vector<vector<int>> dp;
public:
    int rec(int row, int col){
        if(row >  M  || col >N) return 0;
        if(row == M-1 && col == N-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];

        return dp[row][col] = rec(row+1,col)+ rec(row,col+1);
        
    }
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        dp.assign(m+1,vector<int>(n+1,-1));
        return rec(0,0);
    }
};
