class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> numsStore;

        for(int n : nums)
        {
            numsStore.insert(n);
        }

        int highestCount = 0;
        int chain = 0;
        int previousNumber = 0;
        bool newCount = true;
        for(int n : numsStore)
        {
            //std::cout<< n << std::endl;
            if(newCount)
            {
                chain += 1;
                previousNumber = n;
                newCount = false;

                continue;
            }

            if(n == previousNumber + 1)
            {
                chain += 1;
                previousNumber = n;
                continue;
            }
            else
            {
                if(chain > highestCount)
                    highestCount = chain;
                chain = 1;
                newCount = true;
            }
        }

        if(highestCount == 0 || chain > highestCount)
            return chain;

        return highestCount;
    }
};
