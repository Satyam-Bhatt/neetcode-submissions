class Solution {
public:
    int maxArea(vector<int>& heights) {
        int leftPointer = 0;
        int rightPointer = heights.size() - 1;
        int i = 0;
        int greatestArea = 0;
        while( leftPointer < rightPointer)
        {
            int leftValue = heights[leftPointer];
            int rightValue = heights[rightPointer];
            int length = rightPointer - leftPointer;
            int area = 0;

            if(leftValue < rightValue)
            {
                area = leftValue * length;
                leftPointer++;
            }
            else
            {
                area = rightValue * length;
                rightPointer--;
            }

            if(area > greatestArea) greatestArea = area;
            
            i++;
        }

        return greatestArea;

    }
};
