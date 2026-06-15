// PRefix and post fix solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);

        // Pass 1: output[i] = product of all elements to the LEFT of i
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            output[i] = prefix;
            prefix *= nums[i];
        }

        // Pass 2: multiply in the product of everything to the RIGHT of i
        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= suffix;
            suffix *= nums[i];
        }

        return output;
    }
};