class Solution {
public:
    string longestPalindrome(string s) {
        int i=0;
        if (s.size() < 2)
        {
            return s;
        }
        string str = "#";
        for (i = 0; i < s.size(); i++) {
            str += s[i];
            str += "#";
        }
        int strSize = 2 * s.size() + 1;
        vector<int> p(strSize, 0);
        int maxRight = 0;
        int center = 0;
        int maxLen = 1;
        int start = 0;
        int mirror = 0;
        int left = 0;
        int right = 0;
        for (i = 0; i < strSize; i++)
        {
            if (i < maxRight)
            {
                mirror = (2 * center) - i;
                p[i] = min(maxRight - i, p[mirror]);
            }
            left = i - (1 + p[i]);
            right = i + (1 + p[i]);
            while (left >= 0 && right < strSize && str[left] == str[right])
            {
                p[i]++;
                left--;
                right++;
            }
            if (i + p[i] > maxRight)
            {
                maxRight = i + p[i];
                center = i;
            }
            if (p[i] > maxLen)
            {
                maxLen = p[i];
                start = (i - maxLen) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};