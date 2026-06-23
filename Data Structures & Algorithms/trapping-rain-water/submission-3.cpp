class Solution {
   public:
    int trap(vector<int>& height) {
        int leftPointer = 0;
        int rightPointer = height.size() - 1;
        int leftMax = height[leftPointer];
        int rightMax = height[rightPointer];
        int water = 0;

        while (leftPointer < rightPointer) {
            if (height[leftPointer] <= height[rightPointer]) {

                std::cout << leftMax << " || " << height[leftPointer] << std::endl;

                int val = leftMax - height[leftPointer];
                if (val > 0) water = water + val;

                if (height[leftPointer] > leftMax) leftMax = height[leftPointer];

                leftPointer++;
            } else if (height[rightPointer] < height[leftPointer]) {

                std::cout << "2: " << rightMax << " || " << height[rightPointer] << std::endl;

                int val = rightMax - height[rightPointer];
                if (val > 0) water = water + val;

                if (height[rightPointer] > rightMax) rightMax = height[rightPointer];

                rightPointer--;
            }
        }

        return water;
    }
};
