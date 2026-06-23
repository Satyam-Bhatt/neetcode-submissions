// Using a hashmap for a cleaner solution

class Solution {
   public:
    bool isValid(string s) {
        unordered_map<char, char> match = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> parentheses;

        for (char c : s) {
            if (match.count(c)) {  // it's a closing bracket
                if (parentheses.empty() || parentheses.top() != match[c]) return false;
                parentheses.pop();
            } else {
                parentheses.push(c);
            }
        }

        return parentheses.empty();
    }
};
