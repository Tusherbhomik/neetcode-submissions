class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack =[]
        n  =len(tokens)


        for i in range(n):
            if tokens[i]== "+" or tokens[i]=="-" or  tokens[i]=="*" or  tokens[i]=="/":
                b =stack.pop()
                a =stack.pop()
                if tokens[i]== "+":
                    b =a+b
                elif tokens[i]== "-":
                    b =a-b
                elif tokens[i]== "*":
                    b =a*b
                else:
                    b = int(a/b) #  special line
                stack.append(b)
            else: 
                stack.append(int(tokens[i]))
        return int(stack[-1])