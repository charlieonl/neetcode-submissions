class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int length = nums.size();
        int pref = 1;
        vector<int> output(length, 1);
        for (int i = 0; i < length; i++) {
            output[i] *= pref;
            pref *= nums[i];
        }

        int suf = 1;
        for (int i = length - 1; i > -1; i--) {
            output[i] *= suf;
            suf *= nums[i];
        }
        return output;
    }

    

};
