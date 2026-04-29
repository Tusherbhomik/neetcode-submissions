class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(auto a:nums){
            if(a==0) red++;
            else if(a==1) white++;
            else blue++;
        }
        for(int i=0;i<red;i++) nums[i]=0;
        for(int i=red;i<red+white;i++) nums[i]=1;
        for(int i=red+white;i<nums.size();i++) nums[i]=2;
    }
};