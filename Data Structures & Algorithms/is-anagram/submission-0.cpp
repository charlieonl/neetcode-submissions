#include <map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> used1;
        for (char c : s) {
            used1[c]++;
        }
        map<char, int> used2;
        for (char b : t) {
            used2[b]++;
        }
        return used1 == used2;
    }
};
