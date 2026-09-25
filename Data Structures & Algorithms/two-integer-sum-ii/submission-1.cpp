class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int lower = 0;
        int upper = numbers.size() - 1;

        while (lower < upper) {
            if (numbers[lower] + numbers[upper] > target) {
                upper--;
            }
            if (numbers[lower] + numbers[upper] < target) {
                lower++;
            }
            if (numbers[lower] + numbers[upper] == target) {
                return {lower+1, upper+1};
            }
        }
        return {};
    }
};
