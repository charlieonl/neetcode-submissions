#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.length();
        // check empty or len 1 case
        if (s.empty() || size == 1) {
            return true;
        }
        int second = size - 1;
        int first = 0;
        while (first < second) {
            while (!isalnum(s[first]) && first < second) first++;
            while (!isalnum(s[second]) && second > first) second--;
            if (tolower(s[first]) != tolower(s[second])) {
                return false;
            }
            first++;
            second--;
        }

        return true;
    }
};
