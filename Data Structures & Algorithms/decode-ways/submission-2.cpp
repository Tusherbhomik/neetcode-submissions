class Solution {
    int  n ;
    vector<int> dp;
public:
    int rec(string &s, int i){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];

        //loop over choices
        int a =0;
        int b= 0;
        int len1 = s[i]-'0';
        int len2;
        

        if(len1 != 0) a = rec(s,i+1);
        if(i+1<n) {
            len2 = 10*len1+s[i+1]-'0';
            if(len2>=10 && len2<=26) b = rec(s,i+2);
        }
        return dp[i]=a+b;
    }
    int numDecodings(string s) {
        n = s.length();
        dp.resize(n,-1);
        return rec(s,0);
    }
};
