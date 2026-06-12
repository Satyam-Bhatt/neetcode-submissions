class Solution {
public:

    // Encodes a list of strings to a single string.
    // Format: <length>#<string> for each entry.
    // e.g. ["hat","apple"] -> "3#hat5#apple"
    string encode(vector<string>& strs) {
        string result;

        for (int i = 0; i < strs.size(); i++)
        {
            int l = strs[i].size();
            result += to_string(l) + "#" + strs[i];
        }

        return result;
    }

    // Decodes the encoded string back to the original list.
    // At each step:
    //   1. Find the '#' delimiter to extract the length prefix
    //   2. Use that length to slice the actual string that follows
    //   3. Advance i past the chunk (prefix + '#' + string)
    vector<string> decode(string s) {
        vector<string> result;
        if (s.empty()) return result;

        int i = 0;
        while (i < s.size())
        {
            // Find '#' to isolate the length prefix (e.g. "5" in "5#apple")
            int delimPos = s.find('#', i);

            // Parse the length from the substring before '#'
            int sCount = stoi(s.substr(i, delimPos - i));

            // Extract exactly sCount characters after the '#'
            result.push_back(s.substr(delimPos + 1, sCount));

            // Jump i to the start of the next encoded chunk
            i = delimPos + 1 + sCount;
        }

        return result;
    }
};
