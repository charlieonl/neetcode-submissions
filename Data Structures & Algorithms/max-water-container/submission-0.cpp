class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;

        for (int l = 0; l < heights.size(); l++) {
            for (int r = heights.size()-1; r > l; r--) {
                int area = min(heights[l], heights[r]) * (r - l);
                max_area = max(area, max_area);
            }
        }
        return max_area;
    }
};
