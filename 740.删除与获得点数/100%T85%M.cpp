    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() < 1) {
            return 0;
        }

        int maxn = 0;
        for(int& it : nums) {
            maxn = max(maxn, it);
        }
            
        vector<int> cnt(maxn + 1), dp(maxn + 1);
        for(int& it : nums) {
            cnt[it]++;
        }
            
        dp[1] = cnt[1];
        for(int i = 2; i <= maxn; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        }
        return dp[maxn];
    }