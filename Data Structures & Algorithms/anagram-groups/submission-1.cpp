#include <map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<string, vector<string>> res;

        for (auto const s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(s);
        }

        vector<vector<string>> to_return;
        for (auto const r : res) {
            to_return.push_back(r.second);
        }
        return to_return;
    }    
};
