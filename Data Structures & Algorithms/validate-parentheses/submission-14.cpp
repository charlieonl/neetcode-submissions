#include <map>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
       std::map<char, char> pMap = {
        {'{', '}'}, {'[', ']'}, {'(', ')'}
       };
       std::stack<char> stk;
       if (s.length() % 2 != 0) return false;

       for (char& c : s) {
        if (pMap.count(c)) {
            stk.push(pMap[c]);
        } else if (!stk.empty() && c == stk.top()) {
            stk.pop();
        } else {
            return false;
        }
       }
       
       return stk.empty();
    }
};
