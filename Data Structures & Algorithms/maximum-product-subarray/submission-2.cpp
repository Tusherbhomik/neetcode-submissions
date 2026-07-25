class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int prevMax = maxEndingHere;
            int prevMin = minEndingHere;

            maxEndingHere = max({
                nums[i],
                prevMax * nums[i],
                prevMin * nums[i]
            });

            minEndingHere = min({
                nums[i],
                prevMax * nums[i],
                prevMin * nums[i]
            });

            answer = max(answer, maxEndingHere);
        }

        return answer;
    }
};