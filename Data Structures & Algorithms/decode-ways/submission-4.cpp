class Solution {
    int n;
    vector<int> dp;

    int rec(string& s, int i) {
        if (i == n) return 1;// I got a complete way to decoding
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        // Decode one digit
        int oneDigit = rec(s, i + 1);
        // Decode two digits
        int twoDigits = 0;
        if (i + 1 < n) {
            int number = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (number >= 10 && number <= 26) twoDigits = rec(s, i + 2);
        }
        return dp[i] = oneDigit + twoDigits;
    }

public:
    int numDecodings(string s) {
        n = s.size();
        dp.assign(n, -1);
        return rec(s, 0);
    }
};