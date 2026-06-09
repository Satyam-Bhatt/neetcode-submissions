class Solution {
public:
    bool isAnagram(string s, string t) {
         if (s.size() != t.size()) return false;

        int freq[26] = {};

        for (char c : t) freq[c - 'a']++;
        for (char c : s) {
            if (--freq[c - 'a'] < 0) return false;
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
