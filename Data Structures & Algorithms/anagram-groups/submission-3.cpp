class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> to_return;

        std::map<std::vector<char>, std::vector<string>> tracker;
        for (int i = 0; i < strs.size(); i++) {

            std::vector<char> word;
            for (int j = 0; j < strs[i].size(); j++) {
                word.push_back(strs[i][j]);
            }
            std::sort(word.begin(), word.end());
            tracker[word].push_back(strs[i]);
        }
        for (auto const& [groups, lst] : tracker) {
            to_return.push_back(lst);
        }

        return to_return;
    }
};
