    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto &c: s1) {
            mp[c]++;
        }

        int left = 0, right = 0;
        int s1_size = s1.size(), s2_size = s2.size();
        for (; right < s2_size; right++) {
            char c = s2[right];
            mp[c]--;
            while (left <= right && mp[c] < 0) {
                mp[s2[left]]++;
                left++;
            }
            if (right - left + 1 == s1_size) {
                return true;
            }
        }
        return false;
    }