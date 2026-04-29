class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int  m = text1.size(),  n = text2.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(text1[0]==text2[0]) dp[0][0]=1;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                int a = 0, b = 0, c = 0;
                if(row-1>=0) a = dp[row-1][col];
                if(col-1>=0) b = dp[row][col-1];
                if(row-1>=0 && col-1>=0) c = dp[row-1][col-1];
                
                if(text1[row] == text2[col])
                    dp[row][col] = 1 + c;
                else
                    dp[row][col] = max(a,b);
            }
        }
        // for(auto a:  dp){
        //     for (auto b: a) cout<< b<<" ";
        //     cout<<endl;
        // }
        return dp[m-1][n-1];
    }
};
