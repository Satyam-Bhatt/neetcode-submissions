// You can also sort and compare but then the time complexity increases

// GROUP ANAGRAMS
// Approach: Frequency-count key (O(n * k) time, O(n * k) space)
//   where n = number of strings, k = average string length
//
// Core idea: Two strings are anagrams if they have identical character
// frequencies. So we encode each string's frequency profile as a string key and
// group by that key.
//
// Example:
//   "eat" -> count: [1,0,0,0,1,0,...,1,0,0] -> key: "1#0#0#0#1#0#...#1#0#0#"
//   "tea" -> count: [1,0,0,0,1,0,...,1,0,0] -> key: "1#0#0#0#1#0#...#1#0#0#"
//   (same!) "tan" -> count: [1,0,0,0,0,0,...,1,0,1] -> key:
//   "1#0#0#0#0#0#...#1#0#1#"  (different)
//
// Why '#' as delimiter?
//   Without it, count[0]=12, count[1]=0 produces "120" and
//   count[0]=1, count[1]=2, count[2]=0 also produces "120" — collision!
//   With '#': "12#0#" vs "1#2#0#" — unambiguous.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Maps a frequency-key -> all strings that share that key (i.e., are
        // anagrams) Example final state for
        // ["eat","tea","tan","ate","nat","bat"]:
        //   "1#0#...#1#0#1#..." -> ["eat", "tea", "ate"]
        //   "1#0#...#1#1#0#..." -> ["tan", "nat"]
        //   "1#1#...#0#1#0#..." -> ["bat"]
        unordered_map<string, vector<string>> complexMap;

        for (const string& s : strs) // const& avoids copying each string
        {
            // Step 1: Count frequency of each character in s
            // count[0] = freq of 'a', count[1] = freq of 'b', ..., count[25] =
            // freq of 'z' Example: s = "eat"
            //   'e' -> count[4]++  => count[4] = 1
            //   'a' -> count[0]++  => count[0] = 1
            //   't' -> count[19]++ => count[19] = 1
            //   all others remain 0
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
                // 'c' - 'a' maps char to 0-based index:
                //   'a' - 'a' = 0, 'b' - 'a' = 1, ..., 'z' - 'a' = 25
                //
                // Why this works:
                //   Characters are stored as ASCII integers under the hood.
                //   'a' = 97, 'b' = 98, ..., 'z' = 122
                //   So 'e' - 'a' = 101 - 97 = 4  -> count[4] tracks frequency
                //   of 'e'
                //      't' - 'a' = 116 - 97 = 19 -> count[19] tracks frequency
                //      of 't'
                //
                // Why not use the ASCII value directly (i.e. count['e'])?
                //   'e' = 101, so count['e'] would index count[101] — but our
                //   array is only size 26. Subtracting 'a' normalizes the range
                //   to [0, 25] so every lowercase letter fits within the array
                //   bounds.
            }

            // Step 2: Encode the count array as a string key
            // Format: "<count[0]>#<count[1]>#...#<count[25]>#"
            // Example: s = "eat" -> key =
            // "1#0#0#0#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0#"
            //          s = "tea" -> key =
            //          "1#0#0#0#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0#"
            //          (identical)
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]);
                key += "#"; // delimiter to prevent count-bleeding (see top
                            // comment)
            }

            // Step 3: Insert string into the group for this key
            // find() returns complexMap.end() if key doesn't exist yet
            // First time seeing this key: create a new group with {s}
            // Key already exists: append s to the existing group
            // Example progression for ["eat", "tea", "tan"]:
            //   "eat": key not found -> insert {"<eat_key>": ["eat"]}
            //   "tea": key found     -> append  {"<eat_key>": ["eat", "tea"]}
            //   "tan": key not found -> insert {"<tan_key>": ["tan"]}
            //
            // Note: this can also be written as a single line:
            //   complexMap[key].push_back(s);
            // operator[] auto-creates an empty vector if the key is absent,
            // then push_back appends s — one lookup instead of two.
            // The explicit find() + insert() above is kept for readability.
            if (complexMap.find(key) == complexMap.end()) {
                complexMap.insert({key, {s}});
            } else {
                complexMap[key].push_back(s);
            }
        }

        // Step 4: Collect all groups into result
        // We only care about the values (the anagram groups), not the keys.
        // move(v) transfers ownership of each vector instead of copying it.
        // Structured binding: k = key string, v = vector<string> group
        vector<vector<string>> result;
        for (auto& [k, v] : complexMap) {
            result.push_back(move(v));
        }

        return result;
    }
};