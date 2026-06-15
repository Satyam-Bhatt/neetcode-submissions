class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        std::unordered_set<int> zeroPos;
        std::unordered_set<int> negativePos;
        int storeProduct = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zeroPos.insert(i);
                continue;
            } 
            storeProduct = storeProduct * nums[i];
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(zeroPos.size() > 1)
            {
                result.push_back(0);
                continue;
            }
            else if(zeroPos.size() == 1)
            {
                if(zeroPos.find(i) != zeroPos.end())
                {
                    result.push_back(storeProduct);
                    continue;
                }
                result.push_back(0);
                continue;
            }

            int tempNum;
            tempNum = storeProduct / nums[i];
            result.push_back(tempNum);
        }

        std::cout << storeProduct << std::endl;

        return result;
    }
};
