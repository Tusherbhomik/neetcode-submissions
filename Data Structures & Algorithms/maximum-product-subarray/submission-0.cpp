class Solution {
public:
    vector<pair<int,int>> dp;
    vector<bool> vis;

    pair<int,int> rec(vector<int>& nums,int i){
        if(i==0)  return {nums[0],nums[0]};

        if(vis[i]) return dp[i];
        auto [prevMax,prevMin] = rec(nums,i-1);
        int  maxEndHere = max({nums[i], prevMax*nums[i], prevMin*nums[i]});
        int  minEndHere = min({nums[i], prevMax*nums[i], prevMin*nums[i]});
        vis[i] = true;
        return dp[i] = {maxEndHere, minEndHere};
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int  ans = INT_MIN;

        dp.resize(n);
        vis.assign(n, false);

        for(auto i =0;i<n;i++){
            auto [mx, mn] = rec(nums,i);
            ans = max(ans,mx);
        }
        return ans;
    }
};