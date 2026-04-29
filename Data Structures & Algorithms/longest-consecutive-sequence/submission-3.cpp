class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        unordered_set<int>s(nums.begin(),nums.end());

        int  best = 0;
        for(auto &a:nums){
            if(!s.count(a-1)){
                int  curr = a;
                int len = 1;
                while(s.count(curr+1)){
                    curr+=1;
                    len++;
                }
                best = max(best,len);
            }
        }
        return best;
    }
};
