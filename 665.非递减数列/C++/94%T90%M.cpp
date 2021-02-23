    bool checkPossibility(vector<int>& nums) {
        int i = 0, cnt = 0;
        for (; i < nums.size() - 1 && cnt < 2; i++) {
            if (nums[i] > nums[i + 1]) {
                cnt++;
                if (i > 0 && nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i + 1];
                }
            }
        }
        return cnt < 2;
    }