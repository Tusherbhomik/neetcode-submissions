class Solution {
    int n ;
    vector<vector<int>> dp;
public:
    int rec(vector<int>&nums,int i,int previ){
        if(i==n) return 0;
        if(dp[i][previ+1]!=-1) return dp[i][previ+1];

        //loop over all choices 
        //skip
        int ans = rec(nums,i+1,previ);
        //take
        if(previ == -1 || nums[i]>nums[previ]) ans = max(ans, 1+rec(nums,i+1,i));
        return dp[i][previ+1]= ans;

    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return rec(nums,0,-1);
    }
};
