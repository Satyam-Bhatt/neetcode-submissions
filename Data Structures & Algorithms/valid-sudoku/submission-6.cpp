class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // board.size() || board[i].size() || board[i][j]
        std::unordered_set<int> hashSet;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                if (hashSet.find(board[i][j] - '0') == hashSet.end()) {
                    hashSet.insert(board[i][j] - '0');
                } else {
                    return false;
                }
            }
            hashSet.clear();
        }

        for (int i = 0; i < board.size(); i++) {
            hashSet.clear();

            for (int j = 0; j < board[i].size(); j++) {
                if (board[j][i] == '.') continue;
                if (hashSet.find(board[j][i] - '0') == hashSet.end()) {
                    hashSet.insert(board[j][i] - '0');
                } else {
                    return false;
                }
            }
        }

        std::unordered_map<string, std::unordered_set<int>> rowColumnHashMap;

        // Store row and column as keys and then an unordered set with respect to that key and check if it has the element
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                string key = std::to_string((int)i / 3) + std::to_string((int)j / 3);

                rowColumnHashMap[key];
                if (rowColumnHashMap[key].find(board[i][j] - '0') == rowColumnHashMap[key].end()) {
                    rowColumnHashMap[key].insert(board[i][j] - '0');
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
