class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size() - 1;
        int left = 0;

        while (true)
        {
            int sum = numbers[left] + numbers[right];
            if(sum > target)
            {
                right--;
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                return {++left, ++right};
            }
        }
        return {0,0};
    }
};
