class Solution {
    vector<int>dp;
public:
    int rec(int level,int n){
        if(level>n) return 0;
        if(level==n) return 1;
        if(dp[level]!=-1) return dp[level];
        return dp[level]=rec(level+2,n)+rec(level+1,n);
    }
    int climbStairs(int n) {
        dp.resize(n,-1);
        return rec(0,n);
    }
};
