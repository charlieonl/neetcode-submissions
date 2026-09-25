class Solution {
public:
    int characterReplacement(string s, int k) {
        // done once, do again
        unordered_map<char, int> freq;
        int most_freq = 0;
        int longest = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            most_freq = max(freq[s[r]], most_freq);

            while (most_freq + k < r-l+1) {
                freq[s[l]]--;
                l++;
            }
            longest = max(longest, r-l+1);
        }
        return longest;
    }
};
