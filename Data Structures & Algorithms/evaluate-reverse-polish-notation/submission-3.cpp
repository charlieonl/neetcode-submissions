#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        
        for (int i = 0; i < tokens.size(); i++) {    

            if (tokens[i] == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a + b);
            } else if (tokens[i] == "-") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b - a);
            } else if (tokens[i] == "*") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a * b);
            } else if (tokens[i] == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b / a);
            } else {
                stk.push(std::stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
