class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // temperatures[i] == temp on ith day
        // return result where result[i] is the number of days after i
        //      before a warmer temperature appears in the future
        // if no future warmer day, result[i] = 0
        // result[n-1] = 0
        // if temperatures[n-2] < t[n-1], res[n-2] = 1, else res[n-2] = 0
        
        int n = temperatures.size();
        vector<int> result(n, 0);

        for (int i = n-2; i >= 0; i--) {
            int j = i+1;
            // CONTINUE THIS (think DP)
            while (j < n && temperatures[j] <= temperatures[i]) {
                if (result[j] == 0) {
                    j = n;
                } else {
                    j++;
                }
            }
            if (j == n) {
                continue;
            }
            if (temperatures[j] > temperatures[i]) {
                result[i] = j - i;
            }
        }
        return result;
    }
};
