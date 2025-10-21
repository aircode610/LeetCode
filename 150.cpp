class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;

        for (string s : tokens) {
            if (isdigit(s[0]) || isdigit(s[1]))
                stack.push_back(stoi(s));
            else {
                int second = stack.back();
                stack.pop_back();

                int first = stack.back();
                stack.pop_back();

                int res;
                if (s == "+")
                    res = first + second;
                else if (s == "-")
                    res = first - second;
                else if (s == "*")
                    res = first * second;
                else if (s == "/")
                    res = first / second;
                    
                stack.push_back(res);
            }
        }

        return stack.back();
    }
};