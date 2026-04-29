class Solution {
    int  n ;
    vector<int>dp;
public:
    int rec(vector<int>& cost,int cLevel){
        if(cLevel>=n) return 0;
        if(cLevel==n-1) return  cost[cLevel];
        if(dp[cLevel]!=-1) return dp[cLevel];
        return dp[cLevel]= cost[cLevel]+min(rec(cost,cLevel+1),rec(cost,cLevel+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.resize(n,-1);
        return min(rec(cost,0),rec(cost,1));
    }
};
