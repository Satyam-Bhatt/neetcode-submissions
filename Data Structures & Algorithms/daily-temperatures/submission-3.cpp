class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result (temperatures.size(),0);
        stack<int> indices;

        for(int i = 0; i < temperatures.size(); i++)
        {
            if(i + 1 < temperatures.size() && temperatures[i + 1] > temperatures[i])
            {
                result[i] = 1;
                    while(!indices.empty() && temperatures[i + 1] > temperatures[indices.top()])
                    {
                        result[indices.top()] = i - indices.top() + 1;
                        indices.pop();
                    }
            }
            else
            {
                indices.push(i);
            }

        }

        return result;
    }
};
