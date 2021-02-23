    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        int size = intervals.size();
        for (int i = 0; i < size; i++) {
            arr.emplace_back(make_pair(intervals[i][0], i));
        }
        sort(arr.begin(), arr.end());
        vector<int> result;
        for (int i = 0; i < size; i++) {
            result.emplace_back(findFirstBig(arr, intervals[i][1]));
        }
        return result;
    }

    int findFirstBig(vector<pair<int, int>>& arr, int num) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid].first >= num) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == arr.size()) return -1;
        return arr[left].second;
    }