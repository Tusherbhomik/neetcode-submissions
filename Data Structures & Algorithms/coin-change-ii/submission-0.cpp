class Solution {
    int  n;
    vector<vector<int>>dp;
public:
    int rec(int  i,int amount, vector<int>& coins){
        if(amount==0 ) return 1;
        if(amount < 0 ||  i>=n) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int  take  = rec(i, amount-coins[i],coins);
        int  skip  = rec(i+1, amount,coins);
        
        return dp[i][amount]=take+skip;

    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return rec(0,amount,coins);
    }
};
