class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
         std::unordered_set <int> kanishkaSet;

        for(int i = 0; i < nums.size(); i++)
        {
            if(kanishkaSet.count(nums[i]))
                return true;
            kanishkaSet.insert(nums[i]);
        }
        return false;
    }
};