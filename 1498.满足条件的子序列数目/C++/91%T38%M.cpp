    int numSubseq(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> pow_sup(size);
        pow_sup[0] = 1;
        for (int i = 1; i < size; i++) {
            pow_sup[i] = (pow_sup[i - 1] << 1) % 1000000007;
        }

        sort(nums.begin(), nums.end());
        if ((nums[0] << 1) > target) {
            return 0;
        }
        int left = 0, right = size - 1;
        int res = 0;
        while (left <= right) {
            if ((nums[left] + nums[right]) <= target) {
                res = (res + pow_sup[right - left]) % 1000000007;
                left++;
            } else {
                right--;
            }
        }
        return res;
    }