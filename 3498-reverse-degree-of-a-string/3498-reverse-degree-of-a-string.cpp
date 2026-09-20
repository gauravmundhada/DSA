class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            int idx = ch - 'a';
            int rev_index = 26 - idx;

            ans += (rev_index * (i+1));
        }

        return ans;
    }
};