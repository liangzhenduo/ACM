class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0, i, j, k;
        for (i = 0; i < s.length() - ret; i ++) {
            int len = 0;
            for (j = i; j < s.length(); j ++) {
                for (k = i; k < j; k ++) {
                    if (s[k] == s[j]) {
                        len = j - i;
                        i = k;
                        break;
                    }
                }
                if (len > 0) {
                    ret = len > ret ? len : ret;
                    break;
                }
            }
            if (j == s.length() && j - i > ret) {
                return j - i;
            }
        }
        return ret;
    }
};
