class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int start = 0;
        return rec(nums, target, start, end);
    }

    int rec(vector<int>& nums, int target, int start, int end) {
        int mid = (start + end)/2;

        if (start > end) return -1;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return rec(nums, target, start, mid-1);
        } else if (nums[mid] < target) {
            return rec(nums, target, mid+1, end);
        }
        return -1;
    }
};
