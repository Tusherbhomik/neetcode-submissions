class Solution {
    vector<vector<int>>dp;
public:
    bool rec(string &s, int l,int r){
        if(l>=r) return true;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]) return dp[l][r]=rec(s,l+1,r-1);
        return dp[l][r]=false;
    }

    string longestPalindrome(string s) {

        dp.resize(s.length(),vector<int>(s.length(),-1));
        int maxL = 0;
        int startI=0;

        for(int i = 0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(rec(s,i,j)){
                    if(j-i+1 > maxL){
                        maxL = j-i+1;
                        startI = i;
                    }
                }
            }
        }
        return s.substr(startI, maxL);
    }
};