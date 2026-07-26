class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[m - 1][n - 1] = 1;
        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (row == m - 1 && col == n - 1) continue;
                if (row + 1 < m) dp[row][col] += dp[row + 1][col];
                if (col + 1 < n) dp[row][col] += dp[row][col + 1];
            }
        }
        return dp[0][0];
    }
};