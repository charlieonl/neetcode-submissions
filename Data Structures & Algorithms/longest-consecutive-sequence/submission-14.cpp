
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;

        int longest = 1;
        int streak = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] != nums[i-1]+1) {
                streak = 1;
                continue;
            } else if (nums[i] == nums[i-1]+1) {
                streak++;
            }
            longest = std::max(streak, longest);
        }
        return longest;
    }
};
