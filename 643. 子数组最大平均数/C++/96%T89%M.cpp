    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        int i = 0;
        for(; i < k; i++) {
            sum += nums[i];
        }
        double ans = sum;
        for(; i < n; i++) {
            sum = sum - nums[i - k] + nums[i];
            ans = max(ans, sum);
        }
        return ans/k;
    }