class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for (char c : s) {

            if (c == ')' || c == '}' || c == ']')
            {
                if(parentheses.empty()) return false;
            } 

            if (c == '(' || c == '{' || c == '[') {
                parentheses.push(c);
            } else if (c == ')' && !parentheses.empty()) {
                if (parentheses.top() == '(') {
                    parentheses.pop();
                } else
                    return false;
            } else if (c == '}'&& !parentheses.empty()) {
                if (parentheses.top() == '{') {
                    parentheses.pop();

                } else
                    return false;
            } else if (c == ']'&& !parentheses.empty()) {
                if (parentheses.top() == '[') {
                    parentheses.pop();

                } else
                    return false;
            }
        }

        if(!parentheses.empty()) return false;
        return true;
    }
};