class Solution {
    int n;
public:
    bool rec(vector<int>&nums, int i, int sum){
        if(sum == 0) return true; 
        if(i==n) return false;

        //loop over all choices 
        bool ans = rec(nums,i+1,sum);
        ans = ans|| rec(nums,i+1,sum-nums[i]);
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int  sum =0;
        n = nums.size();
        for(auto a:nums) sum+=a;
        if(sum%2==1) return false;
        return rec(nums,0,sum/2);
    }
};
