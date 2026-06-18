class Solution {
   public:
    bool isPalindrome(string s) {

        string newS = "";
        for(char c : s)
        {
            if(isalnum(c))
            {
                char newC = tolower(c);
                newS = newS + newC;
            }
        }

        std::cout<< newS << std::endl;

        for (int i = 0; i < newS.size() / 2; i++) {
            if (newS[i] == newS[newS.size() - 1 - i]) continue;
            return false;
        }
        return true;
    }
};
