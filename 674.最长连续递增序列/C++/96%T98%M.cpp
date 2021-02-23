class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        int length = nums.size();
        for (int i = 0, j = 0; i < length; i = j + 1, j = i) {
            while ((j + 1 < length) && (nums[j] < nums[j + 1])) {
                j++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};