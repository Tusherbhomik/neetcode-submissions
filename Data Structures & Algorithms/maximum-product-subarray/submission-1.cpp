class Solution {
    struct State {
        int maxEndingHere;
        int minEndingHere;
    };

    vector<State> dp;
    vector<bool> vis;//  the ans can be itself minus -1  max  product. so we need seperate condition to know which one  is  already calculated. 

    State rec(vector<int>& nums, int i) {
        if (i == 0) return {nums[0], nums[0]};// at first index, the index value is max and this is  also min 
        if (vis[i]) return dp[i];

        State prev = rec(nums, i - 1);

        int maxEndingHere = max({
            nums[i],
            prev.maxEndingHere * nums[i],
            prev.minEndingHere * nums[i]
        });

        int minEndingHere = min({
            nums[i],
            prev.maxEndingHere * nums[i],
            prev.minEndingHere * nums[i]
        });

        vis[i] = true;
        return dp[i] = {maxEndingHere, minEndingHere};
    }

public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n);
        vis.assign(n, false);
        int answer = INT_MIN;
        for (int i = 0; i < n; i++) {
            answer = max(answer, rec(nums, i).maxEndingHere);
        }

        return answer;
    }
};