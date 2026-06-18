class Solution {
   public:
    bool isPalindrome(string s) {
        int leftPointer = 0;
        int rightPointer = s.size() - 1;

        while (leftPointer < rightPointer) {
            //std::cout << " Left: " << s[leftPointer] << " || Right: " << s[rightPointer] << std::endl;

            char leftLower = tolower(s[leftPointer]);
            char rightLower = tolower(s[rightPointer]);

            if (!isalnum(leftLower)) {
                //std::cout << "Left Alnum" << std::endl;
                leftPointer++;
                continue;
            }
            if (!isalnum(rightLower)) {
                //std::cout << "Right Alnum" << std::endl;
                rightPointer--;
                continue;
            }

            if (leftLower != rightLower) return false;

            leftPointer++;
            rightPointer--;
        }
        return true;
    }
};
