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
            }
            else
            {
                area = rightValue * length;
            }

            if(area > greatestArea) greatestArea = area;


            if(i%2==0)
            {
                leftPointer++;
            }
            else
            {
                rightPointer--;
            }


            i++;
        }

        return greatestArea;

    }
};
