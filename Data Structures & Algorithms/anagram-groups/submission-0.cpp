class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        std::map<vector<int>, vector<string>> complexMap;

        for(string s : strs)
        {
            int count[26] = {0}; 
            for(char c : s)
            {
                count[c - 'a'] += 1;
            }

            vector<int> newCount(count,count + 26);
            if(complexMap.find(newCount) == complexMap.end())
            {
                complexMap.insert({newCount, {s}});
            }
            else
            {
                complexMap[newCount].push_back(s);
            }
        }

        for(auto& [k,v] : complexMap)
        {
            result.push_back(v);
        }


        return result;
    }
};
