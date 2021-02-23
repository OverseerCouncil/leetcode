        int res = 0, zeros = 0, left = 0, length = A.size();
        for (int right = 0; right < length; right++) {
            if (!A[right]) {
                zeros++;
            }
            while (zeros > K) {
                if (!A[left]) {
                    zeros--;
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;