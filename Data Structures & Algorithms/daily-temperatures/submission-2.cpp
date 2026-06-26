class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> stk;  // stores indices

        for (int i = 0; i < temperatures.size(); i++) {
            // Pop all indices whose temperature is less than current
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                int idx = stk.top();
                stk.pop();
                result[idx] = i - idx;
            }
            stk.push(i);
        }
        return result;
    }
};
