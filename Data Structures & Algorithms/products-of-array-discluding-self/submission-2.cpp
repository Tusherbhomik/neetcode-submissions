class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>lp(n,0);
        int prod = 1;

        for(int  i =0;i<n;i++){
            lp[i]=prod;
            prod*=nums[i];
        }
        prod = 1;
        for(int i=n-1;i>=0;i--){
            lp[i]=prod*lp[i];
            prod*=nums[i];
        }
        return lp;
    }
};
