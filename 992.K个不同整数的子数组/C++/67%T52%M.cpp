    int subarraysWithKDistinct(vector<int>& A, int K) {
        return GetMostDistinct(A, K) - GetMostDistinct(A, K - 1);
    }

    int GetMostDistinct(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, ret = 0, size = A.size();
        while (right < size) {
            mp[A[right]]++;
            right++;
            while (mp.size() > K) {
                mp[A[left]]--;
                if (mp[A[left]] == 0) mp.erase(A[left]);
                left++;
            }
            ret += right - left;
        }
        return ret;
    }