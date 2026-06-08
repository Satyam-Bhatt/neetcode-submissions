class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map <int, int> kanishkaMap;

        for(int i = 0; i < nums.size(); i++)
        {
            if(kanishkaMap.find(nums[i]) == kanishkaMap.end())
            {
                kanishkaMap.insert({nums[i], i});
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};