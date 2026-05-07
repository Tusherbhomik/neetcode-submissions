class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [] ## will store index not the height
        area =0
        n = len(heights)

        #here i is right
        for i in range(n):
            if not stack or heights[i]>= heights[stack[-1]]:
                stack.append(i)
            else:
                while stack and  heights[i]< heights[stack[-1]]:
                    height = heights[stack.pop()]
                    if stack: 
                        left  = stack[-1]
                        width = i-left-1
                        area=  max(area,height*width)
                    else:
                        width =i
                        area = max(area,height*width)
                stack.append(i)
        
        while stack:
            index = stack.pop()
            height = heights[index]
            if stack:
                width = n-stack[-1]-1
            else:
                width = n
            area = max(area,height*width)
        return area
            
