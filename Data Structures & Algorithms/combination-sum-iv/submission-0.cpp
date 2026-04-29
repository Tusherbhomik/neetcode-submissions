class Solution {
    vector<int> dp;
public:
    int rec(vector<int>& nums, int target){
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int num : nums){
            ans += rec(nums, target - num);
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return rec(nums, target);
    }
};