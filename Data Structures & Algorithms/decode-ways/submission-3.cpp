class Solution {
    int n;
    vector<int> dp;

public:
    int rec(string &s, int i){
        if(i == n) return 1;

        if(dp[i] != -1) return dp[i];

        if(s[i] == '0') return dp[i] = 0;

        int a = rec(s, i+1);
        int b = 0;

        if(i+1 < n){
            int len2 = (s[i]-'0')*10 + (s[i+1]-'0');
            if(len2 >= 10 && len2 <= 26)
                b = rec(s, i+2);
        }

        return dp[i] = a + b;
    }

    int numDecodings(string s) {
        n = s.length();
        dp.assign(n, -1);
        return rec(s, 0);
    }
};