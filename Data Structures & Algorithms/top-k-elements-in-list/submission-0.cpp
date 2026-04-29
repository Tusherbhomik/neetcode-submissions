class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        for(auto a: nums) ump[a]++;
        vector<pair<int,int>>v;
        for(auto a:ump) v.push_back({a.second, a.first});
        sort(v.begin(),v.end());
        vector<int>ans;
        int j=0;
        for(int i=v.size()-1;i>=0;i--){
            ans.push_back(v[i].second);
            j++;
            if(j==k) break;
        }
        return ans;
    }
};
