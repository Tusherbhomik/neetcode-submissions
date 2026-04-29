class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  n = prices.size();
        bool stock = false;
        int  profit = 0;
        for(int i=0;i<n-1;i++){
            if(!stock && prices[i+1]>prices[i]) {
                profit-=prices[i];
                stock = true;
            }
            else if(stock && prices[i+1]<prices[i]){
                profit+=prices[i];
                stock = false;
            }
        }
        if(stock) profit+=prices[n-1];
        return profit;
    }
};