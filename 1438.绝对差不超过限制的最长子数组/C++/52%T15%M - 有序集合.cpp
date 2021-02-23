    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> mst;
        int left = 0, right = 0;
        int res = 0, len = nums.size();
        while (right < len) {
            mst.insert(nums[right]);
            while (*mst.rbegin() - *mst.begin() > limit) {
                mst.erase(mst.find(nums[left]));
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }