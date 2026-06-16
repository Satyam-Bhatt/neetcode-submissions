class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // board.size() || board[i].size() || board[i][j]
        std::unordered_set<int> hashSet;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (hashSet.find(board[i][j]) == hashSet.end()) {
                    hashSet.insert(board[i][j]);
                } else {
                    return false;
                }
                hashSet.clear();
            }
        }

        hashSet.clear();

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (hashSet.find(board[j][i]) == hashSet.end()) {
                    hashSet.insert(board[j][i]);
                } else {
                    return false;
                }
                hashSet.clear();
            }
        }

        hashSet.clear();

        

        return true;
    }
};
