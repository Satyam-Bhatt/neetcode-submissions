class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> count;
        std::map<int,vector<int>, std::greater<int>> orderedCount;

        for(int i : nums)
        {
            count[i] ++;
        }

        vector<int> result;
        for(auto& [key,v] : count)
        {
            orderedCount[v].push_back(key);
        }

        for(auto& [key,v] : orderedCount)
        {
            //std::cout << "Key: " << key;
            //std::cout << " || Values: " ;
            for(int i : v)
            {
                if(result.size() < k)
                    result.push_back(i);
                else
                    return result;
                //std::cout << i;
            }
            //std::cout<< "\n====" << std::endl;
        }

        return result;
    }
};
