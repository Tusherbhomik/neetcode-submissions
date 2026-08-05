class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq_s1= Counter(s1)
        left  =0
        freq_s2 ={}


        for right in range(len(s2)):
            freq_s2[s2[right]] = freq_s2.get(s2[right],0)+1

            if right-left+1> len(s1):
                freq_s2[s2[left]]-=1
                if freq_s2[s2[left]] == 0:
                    del freq_s2[s2[left]]
                left+=1
            if right-left+1==len(s1) and freq_s1==freq_s2:
                return True
        return False

        


