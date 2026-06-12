class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for(int i = 0; i < strs.size(); i++)
        {
            result += strs[i];
            result += "~";
        }

        //std::cout << result << std::endl;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        string add;
        for(char c : s)
        {
            if(c == '~')
            {
                result.push_back(add);
                add = "";
                continue;
            }
            add = add + c;
            //std::cout << add << std::endl;
        }

        return result;
    }
};
