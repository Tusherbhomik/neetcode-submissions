class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int  l=0;
        int  r = nums.size()-1;
        int minv=INT_MAX;
        while(l<r){
            minv = min(nums[l],nums[r]);
            int m = l+(r-l)/2;

            if(nums[m]<nums[r]) r = m;  
            else if(nums[m]>nums[l]) l = m;
            else{
                l=r;
            }
        }
        return minv;
    }
};