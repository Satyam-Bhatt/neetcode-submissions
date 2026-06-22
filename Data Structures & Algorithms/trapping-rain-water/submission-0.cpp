class Solution {
public:
    int trap(vector<int>& height) {
        int leftPointer = 0;
        int waterStore = 0;
        int i = 0;
        while (leftPointer < height.size())
        {
            if(leftPointer + 1 >= height.size()) return waterStore;
            if(height[leftPointer] > height [leftPointer + 1])
            {
                int tempWaterStore = height[leftPointer] - height [leftPointer + 1];

                if(leftPointer + 2 >= height.size()) return waterStore;

                int rightPointer = leftPointer + 2;

                while (height[leftPointer] > height[rightPointer])
                {
                    tempWaterStore += height[leftPointer] - height [rightPointer];

                    if(rightPointer + 1 >= height.size()) return waterStore;

                    rightPointer ++;
                }

                waterStore += tempWaterStore; 
                leftPointer = rightPointer;
            }
            else
            {
                leftPointer ++;
            }
            i++;
        }
    }
};
