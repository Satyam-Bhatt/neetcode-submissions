class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numsSet;
        int length = 0;
        int longest = 0;

        for(int n : nums)
        {
            numsSet.insert(n);
        }

        for(int n : numsSet)
        {
            if(numsSet.find(n-1) == numsSet.end())
            {
                length = 1;
                while(numsSet.find(n + length) != numsSet.end())
                {
                    length += 1;
                }
                if(length > longest)
                    longest = length;
            }
        }

        return longest;
    }
};
