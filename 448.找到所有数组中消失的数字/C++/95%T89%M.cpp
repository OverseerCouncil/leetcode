    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if (n <= 0) {
            return res;
        }

        for (int i = 0; i < n; i++) {
            int currIndex = abs(nums[i]) - 1;
            if (nums[currIndex] > 0) {
                nums[currIndex] = -nums[currIndex];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res.emplace_back(i + 1);
            }
        }
        return res;
    }