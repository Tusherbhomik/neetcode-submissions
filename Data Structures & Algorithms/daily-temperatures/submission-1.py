class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0]*n
        stack =[]
        for i in range(n-1,-1,-1):
            if not stack:
                stack.append(i)
                result[i]=0
            else:
                while stack and temperatures[i]>= temperatures[stack[-1]]:
                    stack.pop()
                if stack:
                    result[i]= stack[-1]-i
                else :
                    result[i] =0
                stack.append(i)
        return result