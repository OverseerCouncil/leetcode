    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, -1);
        stack<int> s;
        for (int i = 0; i < 2 * size - 1; i++) {
            while (!s.empty() && nums[s.top()] < nums[i % size]) {
                res[s.top()] = nums[i % size];
                s.pop();
            }
            s.push(i % size);
        }
        return res;
    }