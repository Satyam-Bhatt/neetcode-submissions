class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numsStore;
        std::unordered_map<int,int> indexCount;

        for(int n : nums)
        {
            numsStore.insert(n);
        }

        for(int n : numsStore)
        {
            indexCount.insert({n, 1});
            for(int i = 1; i < numsStore.size(); i++)
            {
                if(numsStore.find(n+i) != numsStore.end())
                    indexCount[n] += 1;
                else
                    break;
            }
        }

        int highestValue = 0;
        for(auto& [k,v] : indexCount)
        {
            if(v > highestValue)
                highestValue = v;
            //std::cout << "Key: " << k << " || Value: " << v << std::endl;
        }

        return highestValue;
    }
};
