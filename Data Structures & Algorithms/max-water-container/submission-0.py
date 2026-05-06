class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left  =0;
        right = len(heights)-1
        maxWater  =0;

        while left<right:
            width = right-left
            currHeight = min(heights[left],heights[right])
            area = width* currHeight
            maxWater = max(maxWater,area)

            if heights[left]<heights[right]:
                left = left+1
            else:
                right = right-1
        return maxWater