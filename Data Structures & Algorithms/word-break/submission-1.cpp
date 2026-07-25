class Solution {
    int n;
    vector<int> dp;
    bool rec(string& s, vector<string>& wordDict, int i) {
        if (i == n) return true;
        if (dp[i] != -1) return dp[i];

        for (const string& word : wordDict) {
            int len = word.size();
            if (i + len <= n && s.substr(i, len) == word && rec(s, wordDict, i + len)) return dp[i] = true;
        }
        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp.assign(n, -1);
        return rec(s, wordDict, 0);
    }
};