    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        vector<int> dp;
        for (auto& en : envelopes) {
            int idx = lower_bound(dp.begin(), dp.end(), en[1]) - dp.begin();
            if (idx >= dp.size()) {
                dp.emplace_back(en[1]);
            } else {
                dp[idx] = en[1];
            }
        }
        return dp.size();
    }