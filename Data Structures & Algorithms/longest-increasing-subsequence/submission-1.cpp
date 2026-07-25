class Solution {
    int n;
    vector<vector<int>> dp;

    int rec(vector<int>& nums, int i, int prevIndex) {
        if (i == n) return 0;

        if (dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

        // Option 1: Skip the current element
        int skip = rec(nums, i + 1, prevIndex);

        // Option 2: Take the current element
        int take = 0;
        if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
            take = 1 + rec(nums, i + 1, i);
        }

        return dp[i][prevIndex + 1] = max(skip, take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return rec(nums, 0, -1);
    }
};