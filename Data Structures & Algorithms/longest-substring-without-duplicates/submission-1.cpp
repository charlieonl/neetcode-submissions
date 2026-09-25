#include <set>

// do this question again from scratch

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_set<char> seen;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            while (seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            longest = max(longest, r-l+1);
        }
        return longest;
    }
};
