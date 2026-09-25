
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = -1000;
        int streak = 0;
        int tmp = -1000;

        if (nums.empty()) return 0;

        for (int num : nums) {
            if (tmp == num) continue;
            if (num == tmp + 1 || streak == 0) {
                streak++;
            } else {
                longest = std::max(streak, longest);
                streak = 1;
            }
            longest = std::max(streak, longest);
            tmp = num;
        }
        return longest;
    }
};
