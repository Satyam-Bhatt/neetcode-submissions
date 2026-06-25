class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> number;

        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/")
            {
                int num1 = number.top();
                number.pop();
                int num2 = number.top();
                number.pop();
                int finalNum = 0;
                if (c == "+")
                    finalNum = num2 + num1;
                else if (c == "-")
                    finalNum = num2 - num1;
                else if (c == "*")
                    finalNum = num2 * num1;
                else if (c == "/")
                    finalNum = num2 / num1;
            
                number.push(finalNum);
            }
            else
            {
                int num = std::stoi(c);
                number.push(num);
            }
        }

        return number.top();
    }
};
