class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        maxLen = 0
        freq = {}

        for right in range(len(s)):
            
            freq[s[right]] = freq.get(s[right],0)+1
            while freq[s[right]]>1:
                freq[s[left]]-=1
                left+=1
            maxLen = max(maxLen,right-left+1)
            
        return maxLen