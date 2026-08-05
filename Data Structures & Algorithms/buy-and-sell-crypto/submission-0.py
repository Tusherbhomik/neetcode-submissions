class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minV = float('inf')
        profit  = 0;
        
        for i in range(len(prices)):
            if prices[i]<minV:
                minV = prices[i]
            profit  = max(profit, prices[i]-minV)
        return profit