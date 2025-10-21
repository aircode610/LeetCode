class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> match = { 
            {')', '('}, 
            {']', '['}, 
            {'}', '{'}
        };

        vector<char> stack;
        for (char c : s) {
            if (match.find(c) == match.end()) {
                stack.push_back(c);
            }
            else {
                if (stack.empty() || stack.back() != match[c])
                    return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};