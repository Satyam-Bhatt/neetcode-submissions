class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int pointer = i + 1;

            while (pointer < numbers.size() && numbers[i] + numbers[pointer] < target) {
                pointer++;
            }

            if (pointer < numbers.size() && numbers[i] + numbers[pointer] == target)
                return {++i, ++pointer};
        }

        return {0, 0};
    }
};
