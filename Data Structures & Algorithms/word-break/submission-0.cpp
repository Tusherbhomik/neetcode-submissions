class Solution {
    int n;
    vector<int>  dp;
public:
    bool rec(string &s, vector<string>& wordDict, int i){
        if(i>=n) return true;
        if(dp[i]!=-1) return dp[i];
        // loop over all choices
        bool ans = false;
        for(auto a:wordDict){
            int len =a.length();
            if(s.substr(i,len)== a) ans = ans || rec(s,wordDict,i+len);
        }
        return dp[i]= (int)ans;
    }
    bool wordBreak(string s, vector<string>& wD) {
        n = s.size();
        dp.assign(n,-1);
        return rec(s,wD,0);
    }
};
