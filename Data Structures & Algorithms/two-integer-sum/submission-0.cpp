class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> to_return;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    to_return.push_back(i);
                    to_return.push_back(j);
                    return to_return;
                }
            }
        }
        return to_return;
    }
};
