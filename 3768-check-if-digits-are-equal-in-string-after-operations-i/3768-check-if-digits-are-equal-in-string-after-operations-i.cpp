class Solution {
public:
    void performOp(string &s) {
        string str;
        for (int i = 0; i <= s.length()-2; i++) {
            str += ((s[i] - '0' + s[i + 1] - '0') % 10) + '0';
        }
        s = str;
    }

    bool hasSameDigits(string s) {
        int n = s.length();

        while (s.length() != 2) {
            performOp(s);
        }

        return s[0] == s[1];
    }
};