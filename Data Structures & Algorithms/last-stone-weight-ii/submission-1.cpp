class Solution {
    int n,total;
    vector<vector<int>>dp;
public:

    int rec(vector<int>& stones,int i, int grp1){
        if(i==n) return abs(2*grp1-total);
        if(dp[i][grp1]!=-1) return dp[i][grp1];
        int a = rec(stones,i+1,grp1+stones[i]);
        int b = rec(stones,i+1,grp1);
        return dp[i][grp1]=min(a,b);
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        total =0;
        for (auto a:stones) total+=a;
        dp.assign(n,vector<int>(total,-1));
        return rec(stones,0,0);
    }
};