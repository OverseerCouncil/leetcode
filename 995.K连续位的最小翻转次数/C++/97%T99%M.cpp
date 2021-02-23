    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0, revCnt = 0;
        for (int i = 0; i < n; i++) {
            if (i >= K && A[i - K] > 1) {
                revCnt ^= 1;
                A[i - K] -= 2;
            }
            if (A[i] == revCnt) {
                if (i + K > n) {
                    return -1;
                }
                revCnt ^= 1;
                A[i] += 2;
                ans++;
            }
        }
        return ans;
    }