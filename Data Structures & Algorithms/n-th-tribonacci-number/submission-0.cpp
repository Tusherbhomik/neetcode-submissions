class Solution {
    vector<int>dp;
public:
    int rec(int level){
        cout<<level<<endl;
        
        if(level<=0) return 0;
        if(level==1 || level ==2) return 1;
        if(dp[level]!=-1) return dp[level];
        return dp[level]= rec(level-1)+rec(level-2)+rec(level-3);

    }
    int tribonacci(int n) {
        dp.resize(n+1,-1);
        return rec(n);
    }
};