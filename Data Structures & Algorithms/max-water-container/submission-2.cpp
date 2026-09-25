
// do this question again from scratch

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = -1;
        int l = 0;
        int r = heights.size()-1;

        while (l<r) {
            int area = min(heights[l],heights[r]) * (r-l);
            max_area = max(area, max_area);
            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }
       return max_area;
    }
};
