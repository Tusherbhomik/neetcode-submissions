class Solution {
public:
    int start = 0, maxLen = 0;
    void expand(string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i);
            expand(s, i, i + 1);
        }
        return s.substr(start, maxLen);
    }
};