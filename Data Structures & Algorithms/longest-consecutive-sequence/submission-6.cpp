// Sort the array and then check for the longest chain and keep sotring it

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> numsStore;

        if (nums.size() == 0) return 0;

        for (int n : nums) {
            numsStore.insert(n);
        }

        int highestCount = 0;
        int chain = 1;
        int previousNumber = *numsStore.begin();
        for (int n : numsStore) {
            if (n == previousNumber + 1) {
                chain += 1;
                previousNumber = n;
                continue;
            }
            if (chain > highestCount) highestCount = chain;
            chain = 1;
            previousNumber = n;
        }

        if (highestCount == 0 || chain > highestCount) return chain;

        return highestCount;
    }
};
