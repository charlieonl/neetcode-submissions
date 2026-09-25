#include <map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> count;

        for (int n : nums) {
            count[n]++;
        }
        std::vector<int> seen;

        vector<pair<int, int>> freq;
        for (const auto c : count) {
            
            freq.push_back({c.second, c.first});
        }
        sort(freq.rbegin(), freq.rend());

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(freq[i].second);
        }
        return res;
    }
};
