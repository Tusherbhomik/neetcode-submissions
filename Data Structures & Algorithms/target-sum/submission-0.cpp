class Solution {
    int n ;
    int t;
    int  total;
    vector<vector<int>>  dp;
public:
    int rec(int i,vector<int>& nums, int  curSum ){
        if (i == n) {
            return (curSum == t) ? 1 : 0;
        }

        if(dp[i][curSum+total]!= -1) return dp[i][curSum+total];

        //plus 
        int plus  = rec(i+1,nums,curSum+nums[i]);

        // minus
        int minus  = rec(i+1,nums,curSum-nums[i]);
        return dp[i][curSum+total] = plus+minus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        t = target;
        total = accumulate(nums.begin(), nums.end(), 0);
        dp.assign(n, vector<int>(2 * total + 1, -1));
        return rec(0,nums,0);
    }
};
