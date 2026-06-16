// PRefix and post fix solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        // Prefix
        // Pass 1: output[i] = product of all elements to the LEFT of i
        int fix = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            result[i] = fix;
            fix = fix * nums[i];
        }

        // Post fix
        // Pass 2: multiply in the product of everything to the RIGHT of i
        fix = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] = result[i] * fix;
            fix = fix * nums[i];
        }

        return result;
    }
};
