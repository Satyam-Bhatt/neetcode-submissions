// Bucket Sort does it in O(n) time and space complexity

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        vector<vector<int>> linearCount(nums.size());

        for (int i : nums) {
            count[i]++;
        }

        vector<int> result;
        for (auto& [key, v] : count) {
            linearCount[v - 1].push_back(key);
        }

        for (int i = linearCount.size() - 1; i >= 0; i--) {
            for (int j : linearCount[i]) {
                if (result.size() >= k)
                    return result;
                result.push_back(j);
            }
        }
        return result;
    }
};

// My solution

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         std::unordered_map<int,int> count;
//         std::map<int,vector<int>, std::greater<int>> orderedCount; //
//         Reorders the array descending order vector<int> result;

//         for(int i : nums)
//         {
//             count[i] ++;
//         }

//         // Sort as per value and store the nums as a list/vector
//         for(auto& [key,v] : count)
//         {
//             orderedCount[v].push_back(key);
//         }

//         for(auto& [key,v] : orderedCount)
//         {
//             for(int i : v)
//             {
//                 if(result.size() < k)
//                     result.push_back(i);
//                 else
//                     return result;
//             }
//         }

//         return result;
//     }
// };