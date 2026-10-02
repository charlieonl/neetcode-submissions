class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size = s.length();
        int l = 0;
        int r = 0;
        std::map<char, int> track;
        int maxl = 0;
        int curl = 0;
        track[s[l]]=1;
        
        while (r < size) {
            if (l == r || track[s[r]] <= 1) {
                curl++;
                r++;
                track[s[r]]++;
            } else if (track[s[r]] > 1) {
                track[s[l]]--;
                l++;
                curl--;
            }
            maxl = std::max(curl, maxl);
        }
        return maxl;
    }
};
