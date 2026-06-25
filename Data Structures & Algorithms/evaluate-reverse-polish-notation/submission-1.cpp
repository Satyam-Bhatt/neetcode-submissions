class Solution {
   public:
    int evalRPN(vector<string>& tokens) {

        stack<int> number;
        int last;

        for (string c : tokens) {
            try {
                int num = std::stoi(c);
                number.push(num);
            } catch (...) {

                //while(number.empty())
                //{
                    int num1 = number.top();
                    number.pop();
                    int num2 = number.top();
                    number.pop();
                    int finalNum = 0;
                    if(c == "+")
                    {
                        finalNum = num2 + num1;
                    }
                    else if(c == "-")
                    {
                        finalNum = num2 - num1;
                    }
                    else if(c == "*")
                    {
                        finalNum = num2 * num1;
                    }
                    else if(c == "/")
                    {
                        finalNum = num2 / num1;
                    }
                    number.push(finalNum);
                    //std::cout << finalNum << std::endl;
                    last = finalNum;
                //}
            }
        }

        if(!number.empty()) return number.top();
        return last;
    }
};
