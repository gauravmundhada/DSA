class Solution {
public:
    int minCut(string s) {
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

        vector<int> dp(n); // dp[i] = min cuts to cut s[0..i] into palindrome substr
        for (int i = 0; i < n; i++) {
            if (t[0][i] == true) {
                dp[i]=0; // already a palindrome
            } else {
                dp[i] = INT_MAX;
                for (int k = 0; k < i; k++) {
                    if (t[k+1][i] && 1+dp[k] < dp[i]) {
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }
        return dp[n-1];
    }
};