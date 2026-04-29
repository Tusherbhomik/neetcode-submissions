class Solution {
    int n;
    vector<int> dp;
public:
    int rec(vector<int>& nums, int curHouse){
        if(curHouse>=n) return 0;
        if(curHouse==n-1) return nums[curHouse];
        if(dp[curHouse]!=-1) return dp[curHouse];
        int  a = nums[curHouse]+ rec(nums,curHouse+2);
        int  b= rec(nums,curHouse+1);
        return dp[curHouse] = max(a,b);

    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return rec(nums,0);
    }
};
