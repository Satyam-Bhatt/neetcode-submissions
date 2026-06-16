class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        // Prefix
        int fix = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            result[i] = fix;
            fix = fix * nums[i];
        }

        // Post fix
        fix = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] = result[i] * fix;
            fix = fix * nums[i];
        }

        return result;
    }
};
