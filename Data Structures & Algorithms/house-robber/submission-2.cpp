class Solution {
    int n;
    vector<int> dp;
public:
    int rec(vector<int>& nums, int curHouse) {
        if (curHouse >= n) return 0;
        if (dp[curHouse] != -1) return dp[curHouse];

        int robCurrent = nums[curHouse] + rec(nums, curHouse + 2);
        int skipCurrent = rec(nums, curHouse + 1);

        return dp[curHouse] = max(robCurrent, skipCurrent);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(n,-1);
        return rec(nums,0);
    }
};

    
