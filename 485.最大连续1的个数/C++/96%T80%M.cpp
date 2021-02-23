    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int count = 0;
        for (auto& x: nums) {
            if (x) {
                count++;
            } else {
                max_count = (count > max_count) ? count : max_count;
                count = 0;
            }
        }
        return max_count = (count > max_count) ? count : max_count;
    }