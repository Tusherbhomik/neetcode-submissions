class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = [0] * 26

        left = 0
        max_freq = 0
        ans = 0

        for right in range(len(s)):
            idx = ord(s[right]) - ord('A')
            freq[idx] += 1

            max_freq = max(max_freq, freq[idx])

            while (right - left + 1) - max_freq > k:
                idx = ord(s[left]) - ord('A')
                freq[idx] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans

# আমরা Sliding Window ব্যবহার করি। প্রথমে window-টা ডানদিকে বাড়াতে থাকি এবং প্রতিটি character-এর frequency count করি। একই সাথে window-এর মধ্যে সবচেয়ে বেশি frequency (maxFreq) ট্র্যাক করি। 

# এখন, পুরো window-কে এক character বানাতে হলে window_size - maxFreq সংখ্যক character replace করতে হবে। 
# যদি এই সংখ্যাটি k-এর বেশি হয়ে যায়, তাহলে এই window আর valid নয়। তাই left pointer এগিয়ে window ছোট করি, যতক্ষণ না আবার window_size - maxFreq <= k হয়। 
# যখনই window valid থাকে, তখন তার length দিয়ে answer update করি।
        