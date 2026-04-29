class Solution {
    vector<int>dp;
public:
    int rec(vector<int>& coins, int amount){
        if(amount<0) return INT_MAX;
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int minimum = INT_MAX;

        //loop over choices 
        for(auto i=0;i<coins.size();i++){
            int res = rec(coins, amount - coins[i]);
            if(res != INT_MAX)
                minimum = min(minimum, 1 + res);
        }
        return dp[amount]=minimum;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+1,-1);
        int ans = rec(coins,amount);
        return ans == INT_MAX ? -1:ans;
    }
};
