
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();

        vector<vector<bool>> t(n, vector<bool>(n, false));
        // t[i][j] = t/f - if s[i..j] is a palindrome or not

        // string of length 1
        for (int i = 0; i < n; i++) {
            t[i][i] = true; // s[i..i] is always palindrome
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n-L+1; i++) {
                int j = i+L-1;
                if (L == 2) { // for length 2
                    t[i][j] = (s[i] == s[j]);
                } else { // for length > 2
                    t[i][j] = (s[i] == s[j]) && t[i+1][j-1];
                }
            }
        }

        for (int i = 0; i < n-2; i++) {
            if (t[0][i]) {
                for (int j = i+1; j < n-1; j++) {
                    if (t[i+1][j] && t[j+1][n-1])
                        return true;
                }
            }
        }
        return false;
        
    }
};