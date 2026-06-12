class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for(int i = 0; i < strs.size(); i++)
        {
            int l = strs[i].size();
            result = result + to_string(l) + "#" + strs[i];
        }

        std::cout << result << std::endl;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        string add;
        int jump = 0;
        for(int i = 0; i < s.size(); i = i + jump)
        {
            string count = "";
            int sCount;
            for(int j = i; j < s.size(); j++)
            {
                if(isdigit(s[j]))
                    count = count + s[j];
                else if (s[j] == '#')
                {
                    sCount = std::stoi(count);
                    jump = std::stoi(count) + count.size() + 1;
                    std::cout << jump << " || count: " << count << std::endl;
                    break;
                }
            }

            for(int j = i + count.size() + 1; j < sCount + count.size() + 1 + i; j++)
            {
                add = add + s[j];
            }
            std::cout << add << "\n =======" << std::endl;
            result.push_back(add);
            add = "";
            count = "";

        }

        return result;
    }
};
