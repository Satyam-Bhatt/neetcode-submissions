class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        for (int i = 0; i < numbers.size(); i++) {
            int pointer = i + 1;

            for(int j = i + 1; j < numbers.size(); j++)
            {
                //std::cout << numbers[i] << " || J " << numbers[j] << std::endl;

                if(numbers[i] + numbers[j] > target || numbers[j] > target) break;
                else if(numbers[i] + numbers[j] == target) return{numbers[i], numbers[j]};
            }

            // while (numbers[i] + numbers[pointer] < target || numbers[pointer] < target) {
            //     pointer++;
            // }

            // if (numbers[i] + numbers[pointer] == target)
            //     return {numbers[i], numbers[pointer]};
        }

        return {0,0};
    }
};
