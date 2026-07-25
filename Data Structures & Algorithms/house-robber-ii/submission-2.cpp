class Solution {
    int n;
    vector<int> dp;
public:
    int rec(vector<int>& nums, int curHouse,int end){
        if(curHouse>end) return 0;
        if(dp[curHouse]!=-1) return dp[curHouse];
        int  take = nums[curHouse]+ rec(nums,curHouse+2,end);
        int  skip= rec(nums,curHouse+1,end);
        return dp[curHouse] = max(take,skip);

    }
    int rob(vector<int>& nums) {
        
        n = nums.size();
        if(n==1) return nums[0];
        dp.resize(n,-1);
        int takeFirst = rec(nums,0,n-2);
        dp.clear();
        dp.resize(n,-1);
        int takeLast  = rec(nums,1,n-1);
        return max(takeFirst,takeLast);
    }
};
