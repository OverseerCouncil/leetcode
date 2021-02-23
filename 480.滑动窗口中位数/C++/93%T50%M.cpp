    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        for (int i = k; ;i++) {
            result.emplace_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
            if (i == nums.size()) {
                return result;
            }
            window.insert(nums[i]);
            if (nums[i] < *mid) {
                mid--;
            }
            if (nums[i - k] <= *mid) {
                mid++;
            }
            window.erase(window.lower_bound(nums[i - k]));
        }
    }