class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        int cnt;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            cnt=0;
            int m =i;
            while(m){
                m = m&(m-1);
                cnt++;
            }
            ans.push_back(cnt);
        }  
        return ans; 
    }
};
