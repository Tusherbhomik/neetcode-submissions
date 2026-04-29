class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int  n =nums.size();
        int  cnt1=0, cnt2=0;
        int cand1= 0, cand2 = 0;
        for(auto &a:nums){
            
            if(cand1==a)cnt1++;
            else if(cand2==a)cnt2++;
            else if(cnt1==0){
                cand1= a;
                cnt1++;
            }else if(cnt2==0){
                cand2=a;
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        cout<<cand1<<" "<<cand2<<endl;
        for(auto &a:nums){
            if(a==cand1)cnt1++;
            else if(a==cand2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(cand1);
        if(cnt2>n/3) ans.push_back(cand2);
        return ans;
    }
};