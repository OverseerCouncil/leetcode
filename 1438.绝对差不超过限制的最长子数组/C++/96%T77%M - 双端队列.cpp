    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_queue, min_queue;
        int l = 0, r = 0, res = 0, len = nums.size();
        while (r < len) {
            while (!max_queue.empty() && nums[r] > max_queue.back()) 
                max_queue.pop_back();
            while (!min_queue.empty() && nums[r] < min_queue.back())    
                min_queue.pop_back();
            min_queue.push_back(nums[r]);
            max_queue.push_back(nums[r]);
            r++;
            while (max_queue.front() - min_queue.front() > limit) {
                if (max_queue.front() == nums[l]) 
                    max_queue.pop_front();
                if (min_queue.front() == nums[l]) 
                    min_queue.pop_front();
                l++;
            }
            res = max(res, r - l);
        }
        return res;
    }