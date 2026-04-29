class Solution {
    int n ;
    vector<vector<int>>dp;
public:

    int  rec(vector<int>& stoneValue, bool Alice,int i){
        if(i>=n) return 0;
        if(Alice && dp[i][0]!= INT_MIN) return dp[i][0]; 
        if(!Alice && dp[i][1]!= INT_MIN) return dp[i][1]; 
        //loop over all choices 
        int ansA= INT_MIN;
        int ansB = INT_MAX;
        int sum = 0;
        if(Alice) {
            for(int ch=0;i+ch<n && ch<3;ch++){
                sum+= stoneValue[i+ch];
                ansA = max(ansA, rec(stoneValue,false,i+ch+1)+sum);
            }
            // ansA =max(ansA, stoneValue[i]+ rec(stoneValue,false,i+1));
            // if(i+1 <n)
            // ansA = max(ansA, stoneValue[i]+stoneValue[i+1]+ rec(stoneValue,false,i+2));
            // if(i+2 <n)
            // ansA = max(ansA, stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]+rec(stoneValue,false,i+3));
        }else {
            for(int ch=0;i+ch<n && ch<3;ch++){
                sum+= stoneValue[i+ch];
                ansB = min(ansB, rec(stoneValue,true,i+ch+1)-sum);
            }
            // ansB = min(ansB,rec(stoneValue,true,i+1)-stoneValue[i]);
            // if(i+1 <n)
            // ansB = min(ansB,rec(stoneValue,true,i+2)-stoneValue[i]-stoneValue[i+1]);
            // if(i+2 <n)
            // ansB = min(ansB,rec(stoneValue,true,i+2)-stoneValue[i]-stoneValue[i+1]-stoneValue[i+2]);
        }
        if(Alice) return dp[i][0]=ansA ;
        return dp[i][1]=ansB;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n,vector<int>(2,INT_MIN));
        int ans =  rec(stoneValue,true,0);
        cout<<ans<<endl;
        if(ans == 0)return "Tie";
        else if(ans>0) return "Alice";
        return "Bob";
    }
};