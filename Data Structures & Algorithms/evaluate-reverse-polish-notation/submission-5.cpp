// Try catch is expensive

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> number;

        for (string c : tokens) {
            try {
                int num = std::stoi(c);
                number.push(num);
            } catch (...) {
                int num1 = number.top();
                number.pop();
                int num2 = number.top();
                number.pop();
                int finalNum = 0;
                if (c == "+") {
                    finalNum = num2 + num1;
                } else if (c == "-") {
                    finalNum = num2 - num1;
                } else if (c == "*") {
                    finalNum = num2 * num1;
                } else if (c == "/") {
                    finalNum = num2 / num1;
                }
                number.push(finalNum);
            }
        }

        return number.top();
    }
};