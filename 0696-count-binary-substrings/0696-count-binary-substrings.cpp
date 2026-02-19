class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int curr = 1;
        int prev = 0;
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                ans += min(curr, prev);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
        }
        return ans + min(prev, curr);
    }
};