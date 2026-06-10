class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); i++) {
            int valueToFind = target - nums[i];
            if (hashMap.find(valueToFind) != hashMap.end()) {
                return {hashMap.at(valueToFind), i};
            }
            hashMap[nums[i]] = i;
        }

        return {};
    }
};
