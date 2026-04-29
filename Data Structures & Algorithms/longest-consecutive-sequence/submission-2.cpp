class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        unordered_set<int>s;
        int maxL = 1;
        int len;
        for(auto &a:nums) s.insert(a);
        for(auto &a:nums){
            if(s.find(a-1)==s.end()) {//if not found
                len = 1;
                while(s.find(a+len)!=s.end()){
                    s.erase(a+len);
                    len++;
                }
                maxL = max(maxL,len);
            }
        }
        return maxL;
    }
};
