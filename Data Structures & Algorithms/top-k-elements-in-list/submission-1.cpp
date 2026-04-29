class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        for(auto a: nums) ump[a]++;


        //using bucket  sort
        vector<vector<int>> bucket(nums.size()+1);
        for(auto &[n,c]:ump){
            bucket[c].push_back(n);
        }
        vector<int> ans;
        for(int i= bucket.size()-1;i>=0 && ans.size()<k;i--){
            for(auto a:bucket[i]){
                ans.push_back(a);
            }
        }
        return ans;
    }
};
