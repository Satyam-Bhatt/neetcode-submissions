class Solution {
public:
    bool isAnagram(string s, string t) {
         if (s.size() != t.size())
            return false;

        std::unordered_map<char, int> letters;

        for (int i = 0; i < t.size(); i++) {
            if (letters.find(t[i]) == letters.end())
                letters.insert({t[i], 1});
            else {
                letters[t[i]] = letters[t[i]] + 1;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (letters.find(s[i]) == letters.end() || letters[s[i]] == 0) {
                return false;
            }
            letters[s[i]] = letters[s[i]] - 1;
        }

        return true;
    }
};

// A better solution where you use characters as direct array index as "a" -> 0, "b" -> 1 etc. 
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) return false;

//         int freq[26] = {};

//         for (char c : t) freq[c - 'a']++;
//         for (char c : s) {
//             if (--freq[c - 'a'] < 0) return false;
//         }

//         return true;
//     }
// };
