    int findShortestSubArray(vector<int>& nums) {
        int res = 0, degree = 0, size = nums.size();
        unordered_map<int, int> count, first_pos;
        for (int i = 0; i < size; i++) {
            if (!first_pos.count(nums[i])) {
                first_pos[nums[i]] = i;
            }
            if (++count[nums[i]] > degree) {
                degree = count[nums[i]];
                res = i - first_pos[nums[i]] + 1;
            } else if (count[nums[i]] == degree) {
                res = min(res, i - first_pos[nums[i]] + 1);
            }  
        }
        return res;   
    }