    vector<int> pre_sum;

    NumArray(vector<int>& nums) {
        int length = nums.size();
        pre_sum.resize(length + 1);
        for (int i = 1; i <= length; i++) {
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return pre_sum[j + 1] - pre_sum[i];
    }