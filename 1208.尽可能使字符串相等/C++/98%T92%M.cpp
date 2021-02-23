    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        int len = s.length();
        int cost = 0;
        while (right < len) {
            cost += abs(s[right] - t[right]);
            if (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            right++;
        }
        return right - left;
    }