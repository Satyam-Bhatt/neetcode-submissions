class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> stk; // stores indices

    for (int i = 0; i < n; i++) {
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
