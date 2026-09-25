class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;
        int left = 0;
        int max_count = 0;

        unordered_map<char, int> count;

        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            if (count[s[right]] > max_count) {
                max_count = count[s[right]];
            }
            while (right-left+1 - max_count > k) {
                count[s[left]]--;
                left++;
            }
            longest = max(right-left+1, longest);
        }
        return longest;
    }
};
