class Solution {
    int n;
    vector<vector<int>> dp;
public:
    bool rec(vector<int>&nums, int i, int sum){
        if(sum == 0) return true; 
        if(i==n) return false;

        if(dp[i][sum] != -1) return dp[i][sum];

        //loop over all choices 

        bool ans = rec(nums, i+1, sum);
        
        if(nums[i] <= sum)
            ans = ans || rec(nums, i+1, sum - nums[i]);

        return dp[i][sum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int  sum =0;
        n = nums.size();
        for(auto a:nums) sum+=a;
        if(sum%2==1) return false;
        dp.assign(n, vector<int>(sum/2 + 1, -1));
        return rec(nums,0,sum/2);
    }
};
