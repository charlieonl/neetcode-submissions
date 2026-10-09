class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // CHANGED: Check sizes before accessing s2
        if (s1.size() > s2.size()) return false;
        if (s1.empty()) return true;

        std::map<char, int> map1;
        for (char s : s1) {
            map1[s]++;
        }

        int left = 0;

        // CHANGED: Start right at 0 instead of 1
        int right = 0;

        std::map<char, int> map2;

        // REMOVED: Initializing map2 with s2[left] and s2[right]
        // We now add characters inside the while loop

        while (right < s2.size()) {

            // ADDED: Add the current right character to the window
            map2[s2[right]]++;

            // CHANGED: Only shrink the window when it exceeds s1's length
            // This replaces all your original if/else pointer logic
            if (right - left + 1 > s1.size()) {
                map2[s2[left]]--;

                // ADDED: Remove keys with a count of 0
                // Otherwise map1 == map2 can incorrectly return false
                if (map2[s2[left]] == 0) {
                    map2.erase(s2[left]);
                }

                left++;
            }

            // KEPT: Compare the two maps
            if (map2 == map1) return true;

            // CHANGED: Always increment right by 1
            right++;
        }

        return false;
    }
};