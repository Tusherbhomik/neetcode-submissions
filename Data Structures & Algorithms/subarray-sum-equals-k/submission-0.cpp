class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n,0);

        unordered_map<int,int>mp;
        pre[0]=nums[0],mp[0]=1;
        int ret=0;

        for(int i=0;i<n;i++){
            if(i>0)
                pre[i]=pre[i-1]+nums[i];
            int target=pre[i]-k;

            ret+=mp[target];
            mp[pre[i]]++;
        }
        return ret;

    }
};